////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/BasicBuffer.hpp>
#include <tachyon/TachyonLog.hpp>
#include <tachyon/Buffer.hpp>
#include <tachyon/scene/Scene3D.hpp>
#include <tachyon/camera/NullCamera.hpp>
#include <tachyon/gpu/ViContext.hpp>
#include <tachyon/gpu/ViPipeline.hpp>
#include <tachyon/gpu/Visualizer.hpp>
#include <tachyon/gfx/PushData.hpp>
#include <tachyon/host/Window.hpp>
#include <tachyon/scene/Render3D.hpp>

namespace yq {
    namespace tachyon {

        
        struct Scene3D::Thing {
            std::vector<ViBO>   vbos;
            std::vector<ViBO>   ibos;

            Thing(Visualizer& viz, const Pipeline& pipe, Rendered* object) 
            {
                const ViPipeline&   vp  = viz.create(pipe);
                size_t i;

                auto& vc    = pipe.config().vbos;
                if(!vc.empty()){
                    vbos.resize(vc.size());
                    for(i=0;i<vbos.size();++i){
                        vbos[i] = vp.vbos[i];
                        vbos[i].update(viz, vc[i], object);
                    }
                }
                    
                auto& ic    = pipe.config().ibos;
                if(!ic.empty()){
                    ibos.resize(ic.size());
                    for(i=0;i<ibos.size();++i){
                        ibos[i] = vp.ibos[i];
                        ibos[i].update(viz, ic[i], object);
                    }
                }
            }
            
            void        update(Visualizer& viz, const Pipeline& pipe, Rendered* object)
            {
                size_t i;
                auto& vc    = pipe.config().vbos;
                for(i=0;i<vbos.size();++i)
                    vbos[i].update(viz, vc[i], object);
                    
                auto& ic    = pipe.config().ibos;
                for(i=0;i<ibos.size();++i)
                    ibos[i].update(viz, ic[i], object);
            }
        };
        
        Scene3D::Scene3D()
        {
            m_camera        = new NullCamera();
            m_scene         = new Scene();
        }
        
        Scene3D::~Scene3D()
        {
            clear_map();
        }
        
        namespace {
            Tristate    unite(Tristate specific, Tristate general)
            {
                return (specific == Tristate::INHERIT) ? general : specific;
            }
            
            template <typename T>
            bool    assign_change(T& cur, T newval)
            {
                if(cur == newval)
                    return false;
                cur = newval;
                return true;
            }
        }

        void        Scene3D::clear_map()
        {
            for(auto& i : m_things)
                delete i.second;
            m_things.clear();
        }

        Scene3D::Thing&      Scene3D::thing(const Pipeline& p, Rendered* r)
        {
            auto [j,f]  = m_things.emplace(DKey(p.id(), r->id()), nullptr);
            if(f){
                j->second   = new Thing(*m_viz, p, r);
            } else {
                j->second->update(*m_viz, p, r);
            }
            return *(j->second);
        }
        
        void    Scene3D::vulkan_(ViContext& u)
        {
            if(u.viz() != m_viz){
                //  change... dump old
                m_viz               = u.viz();
            }
            
            Camera::Params      cparams;
            cparams.screen  = (Size2D) u.window()->framebuffer_size();
            glm::dmat4  cam_matrix = m_camera->world2screen(cparams);
            VkPipeline  prev    = nullptr;
            StdPushData push;
            push.time  = m_scene -> utime;
            
            for(RenderedPtr r : m_scene->things){
                if(!r)
                    continue;
                PipelineCPtr    pipe    = r->pipeline();
                if(!pipe)
                    continue;
                const ViPipeline&   vp   = m_viz->create(*pipe);
                if(!vp.pipeline)
                    continue;
                
                auto& cfg   = pipe->config();
                Thing&  t   = thing(*pipe, r.ptr());


                    
                    //  hint that the entire pipeline/object needs to be resorted
                
                const Render3D *r3  = dynamic_cast<const Render3D*>(r.ptr());

                Tristate        wireframe   = unite(r->wireframe(), m_wireframe);
                VkPipeline      vkpipe      = (wireframe == Tristate::YES) ? vp.wireframe : vp.pipeline;

                //  =================================================
                //      SET THE PIPELINE

                if(vkpipe && (vkpipe != prev)){
                    vkCmdBindPipeline(u.command(), VK_PIPELINE_BIND_POINT_GRAPHICS, vkpipe);
                    prev   = vkpipe;
                }
                
                
                //  =================================================
                //      PUSH THE CONSTANTS

                switch(cfg.push.type){
                case PushConfigType::Full:
                    if(r3){
                        push.matrix  = cam_matrix * r3->model2world();
                        vkCmdPushConstants(u.command(), vp.layout, vp.shaders, 0, sizeof(push), &push );
                    }
                    break;
                case PushConfigType::View:
                    push.matrix  = cam_matrix;
                    vkCmdPushConstants(u.command(), vp.layout, vp.shaders, 0, sizeof(push), &push );
                    break;
                case PushConfigType::Custom:
                    if(cfg.push.fetch){
                        PushBuffer      bd;
                        cfg.push.fetch(r.ptr(), bd);
                        vkCmdPushConstants(u.command(), vp.layout, vp.shaders, 0, bd.size(), bd.data());
                    }
                    break;
                case PushConfigType::None:
                default:
                    // no push constant desired... which is fine.
                    break;
                }
                
                //  =================================================
                //      VERTEX BUFFERS

                uint32_t    vmax    = 0;
                uint32_t    VN      = cfg.vbos.size();
                if(VN){
                    for(uint32_t i=0;i<VN;++i){
                        VkDeviceSize    zero{};
                        vmax    = std::max(vmax, t.vbos[i].count);
                        vkCmdBindVertexBuffers(u.command(), i,  1, &t.vbos[i].buffer, &zero);
                    }
                }
                
                //  =================================================
                //      INDEX BUFFERS
                
                uint32_t    VI      = cfg.ibos.size();
                if(VI){
                    for(uint32_t i=0;i<VI;++i){
                        vkCmdBindIndexBuffer(u.command(), t.ibos[i].buffer, 0, (VkIndexType)(cfg.ibos[i].type.value()));
                        vkCmdDrawIndexed(u.command(), t.ibos[i].count, 1, 0, 0, 0);  // possible point of speedup in future
                    }
                } else {
                    vkCmdDraw(u.command(), vmax, 1, 0, 0);
                }
            }
        }
        
        void    Scene3D::set_camera(Ref<Camera> v)
        {
            if(v)
                m_camera    = v;
        }
        
        void    Scene3D::set_scene(Ref<Scene> v)
        {
            if(v)
                m_scene     = v;
        }

        void    Scene3D::set_wireframe(Tristate v)
        {
            m_wireframe     = v;
        }
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::Scene3D)
