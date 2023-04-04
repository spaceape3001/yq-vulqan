////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL's QT UTILITIES
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/UniqueID.hpp>
#include <basic/Guarded.hpp>

#include <engine/preamble.hpp>
#include <tachyon/ViewerCreateInfo.hpp>
#include <tachyon/host/Monitor.hpp>
#include <tachyon/enum/PresentMode.hpp>
#include <tachyon/gpu/Visualizer.hpp>
#include <tachyon/gpu/ViQueues.hpp>
#include <engine/vulqan/VqPipeline.hpp>
#include <math/preamble.hpp>

#include <vk_mem_alloc.h>


#include <tbb/spin_rw_mutex.h>

#include <atomic>
#include <set>
#include <thread>

struct GLFWwindow;


namespace yq {
    namespace engine {
        class Viewer;
        struct ViewerCreateInfo;
        struct VqObject;
        
        using ViTick    = std::atomic<uint64_t>;
        
        using tachyon::ViQueues;
        
        struct ViBuffer : not_copyable, not_moveable {
            std::unique_ptr<VqBuffer>   vq;
            uint64_t                    rev = 0;
            
            ViBuffer();
            ~ViBuffer();
        };

        struct ViBufferMap : not_copyable, not_moveable {
            std::map<uint64_t, ViBuffer*>    buffers;
            std::pair<ViBuffer*,bool>    buffer(uint64_t i)
            {
                auto j = buffers.find(i);
                if(j!=buffers.end())
                    return {j->second,false};
                ViBuffer*p  = new ViBuffer;
                buffers[i] = p;
                return {p,true};
            }
            
            ViBufferMap();
            ~ViBufferMap();
        };

        struct ViPipeline : public ViBufferMap {
            std::unique_ptr<VqPipeline> vq;
            
            ViPipeline();
            ~ViPipeline();
        };
        
        struct ViObject : public ViBufferMap {
        
            ViObject();
            ~ViObject();
        };
        
        

        /*! \brief Visualizer is the private data for the viewer
                
            This structure is the raw vulkan/GLFW/etc
            
            \note Eventually this will merge into viewer itself
        */
        struct Visualizer : public tachyon::Visualizer {
        
            Viewer*                             m_viewer                = nullptr;
            
            
            
            //std::thread         builder;
            //uint64_t            pad[8];
            //std::atomic<bool>   terminating                 = false;
            
            std::map<uint64_t, ViPipeline*>     pipelines;
            std::map<uint64_t, ViObject*>       objects;
            
            std::pair<ViPipeline*,bool>     pipeline(uint64_t i);
            std::pair<ViObject*,bool>       object(uint64_t i);
            
            void    run();
            
            
            Visualizer(const ViewerCreateInfo&, Viewer*);
            ~Visualizer();
            void                _ctor(const ViewerCreateInfo&);
            void                _dtor();

            bool    graphic_draw();
        };
    }
}
