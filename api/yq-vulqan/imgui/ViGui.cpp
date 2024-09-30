////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViGui.hpp"

#include <yq-toolbox/basic/AutoReset.hpp>
#include <yq-toolbox/basic/DelayInit.hpp>
#include <yq-toolbox/io/FileResolver.hpp>
#include <yq-toolbox/math/integer.hpp>

#include <yq-vulqan/logging.hpp>
#include <yq-vulqan/asset/Asset.hpp>
#include <yq-vulqan/image/Image.hpp>
#include <yq-vulqan/pipeline/Pipeline.hpp>
#include <yq-vulqan/pipeline/PipelineWriter.hpp>
#include <yq-vulqan/sampler/Sampler.hpp>
#include <yq-vulqan/shader/Shader.hpp>
#include <yq-vulqan/texture/Texture.hpp>
#include <yq-vulqan/v/VqStructs.hpp>
#include <yq-vulqan/viz/ViBuffer.hpp>
#include <yq-vulqan/viz/ViContext.hpp>
#include <yq-vulqan/viz/ViImage.hpp>
#include <yq-vulqan/viz/ViManager.hpp>
#include <yq-vulqan/viz/ViPipeline.hpp>
#include <yq-vulqan/viz/ViPipelineLayout.hpp>
#include <yq-vulqan/viz/ViSampler.hpp>
#include <yq-vulqan/viz/ViSwapchain.hpp>
#include <yq-vulqan/viz/ViTexture.hpp>
#include <yq-vulqan/viz/ViVisualizer.hpp>
#include <yq-vulqan/widget/Widget.hpp>

#include <backends/imgui_impl_glfw.h>

/*
    This file leans heavily on imgui_impl_vulkan.cpp for patterns, some code is 
    copied.  As we're basically leaning into our vulkan engine instead.
*/


namespace yq::tachyon {

    static constexpr const size_t kInitCapacity     = 8192;
    static constexpr const size_t kBufferAlignment  = 256;
    
    struct ViGui::Push {
        glm::vec2   scale;
        glm::vec2   translate;
        float       z   = 0.;
    };

    struct ViGui::G {
        const Pipeline* pipeline   = nullptr;
        ViPipelineOptions   pipeline_options{
            .wireframe  = Tristate::NO
        };
        
        struct {
            uint32_t        binding   = 0;
            SamplerCPtr     sampler;
            TextureInfo     texInfo;
        } font;
        
        struct {
            uint32_t        binding = 0;
        } vertex, index;
        
        G();
        ~G();
    };
    
    ViGui::G::G()
    {
        Pipeline*   p    = new Pipeline;
        pipeline    = p;
        p -> dynamic_states({DynamicState::Viewport, DynamicState::Scissor });
        p -> line_width(1.0);
        p -> shaders({"imgui/vigui.vert", "imgui/vigui.frag" });
        p -> culling(CullMode::None);
        p -> polygons(PolygonMode::Fill);
        p -> front(FrontFace::CounterClockwise);
        p -> wireframe_permitted(false);
        
        p -> vertex<ImDrawVert>(REFRESH)
                .attribute(&ImDrawVert::pos, DataFormat::R32G32_SFLOAT)
                .attribute(&ImDrawVert::uv, DataFormat::R32G32_SFLOAT)
                .attribute(&ImDrawVert::col, DataFormat::R8G8B8A8_UNORM)
        ;
        p -> index<ImDrawIdx>(REFRESH);
        p -> texture(REFRESH);
        
        p -> push<Push>();
        font.sampler = new Sampler({
            .flags  = {},
            .addressMode = SamplerAddressModeUVW(ALL, SamplerAddressMode::Repeat),
            .maxAnisotropy  = 1.0f,
            .minLod = -1000,
            .maxLod = 1000
        });
    }
    
    ViGui::G::~G()
    {
    }

    ViGui::G&   ViGui::global()
    {
        static G    s_ret;
        return s_ret;
    }
    
    ////////////////////////////////////////////////////////////////////////////

    ViGui::ViGui(ViVisualizer& viz, const ViGuiOptions& options) : m_viz(&viz)
    {
        if(!_init(options)){
            _kill();
        }
    }
    
    ViGui::~ViGui()
    {
        _kill();
    }

    bool    ViGui::_init(const ViGuiOptions& options)
    {
        G&  g   = global();

        m_context   = ImGui::CreateContext();
        ImGui::SetCurrentContext(m_context);
        ImGui_ImplGlfw_InitForVulkan(m_viz->_window(), false);
        
        ImGuiIO& io = ImGui::GetIO();
        io.BackendRendererName      = "yq::tachyon::ViGui";
        io.BackendRendererUserData  = this;
        io.BackendFlags |= ImGuiBackendFlags_RendererHasVtxOffset;  // We can honor the ImDrawCmd::VtxOffset field, allowing for large meshes.
        
        //m_pipelineLayout        = m_viz -> pipeline_layout_create(g.pipeline);
        m_pipeline              = m_viz -> pipeline_create(g.pipeline);
        m_pipelineLayout        = m_pipeline -> layout();
        
        //new ViPipelineLayout(*m_viz, g.pipeline);
        //m_pipeline              = new ViPipeline(*m_viz, m_pipelineLayout, g.pipeline_options);
        m_font.sampler          = new ViSampler(*m_viz, *g.font.sampler);
        
        VkDescriptorSetLayout   descLay = m_pipelineLayout -> descriptor_set_layout();
        m_font.descPool         = m_viz->descriptor_pool();

        VqDescriptorSetAllocateInfo allocInfo;
        allocInfo.descriptorPool        = m_font.descPool;
        allocInfo.descriptorSetCount    = 1;
        allocInfo.pSetLayouts           = &descLay;
        
        VkResult    res = vkAllocateDescriptorSets(m_viz->device(), &allocInfo, &m_font.descriptor);
        if(res != VK_SUCCESS){
            vizWarning << "Unable to allocate descriptor sets.  VkResult " << (int32_t) res;
            return false;
        }

        _font_update();
        return true;
    }
    
    void    ViGui::_kill()
    {
        if(m_font.descriptor){
            vkFreeDescriptorSets(m_viz->device(), m_font.descPool, 1, &m_font.descriptor);
        }
        
        m_font.descriptor       = nullptr;
        m_font.descPool         = nullptr;
        m_font.texture          = {};
        m_font.image            = {};
        m_font.sampler          = {};
        
        m_pipeline              = {};
        m_pipelineLayout        = {};
        m_viz                   = nullptr;

        if(m_context){
            ImGui::SetCurrentContext(m_context);
            ImGui_ImplGlfw_Shutdown();
            ImGuiIO& io = ImGui::GetIO();
            io.BackendRendererName      = nullptr;
            io.BackendRendererUserData  = nullptr;
            io.BackendFlags            &= ~ImGuiBackendFlags_RendererHasVtxOffset;
            ImGui::DestroyContext(m_context);
            m_context           = nullptr;
        }
    }

    const ImFont*   ViGui::_font_load(const std::filesystem::path& fp, float pixel_size)
    {
        if(fp.empty())
            return nullptr;
        const ImFont* ret = ImGui::GetIO().Fonts->AddFontFromFileTTF(fp.c_str(), pixel_size);
        if(ret)
            m_update |= U::Font;
        return ret;
    }

    bool    ViGui::_font_update()
    {
        G&  g   = global();

        int             width = 0,  height = 0;
        glm::u8vec4*    pixels  = nullptr;
        ImGui::GetIO().Fonts->GetTexDataAsRGBA32((unsigned char**) &pixels, &width, &height);
        size_t          count   = width * height;
        if(count == 0)
            return false;
        
        ImageCPtr   image  = new Image(ImageInfo{
                .size   = Size4U((unsigned) width,(unsigned) height, 1, 1),
                .format = DataFormat::R8G8B8A8_UNORM
            }, 
            Memory(COPY, pixels, count)
        );
        
        m_font.image      = new ViImage(*m_viz, *image);
        m_font.texture    = new ViTexture(*m_viz, m_font.image, m_font.sampler, g.font.texInfo);
        
        VkDescriptorImageInfo   imgInfo {
            .sampler        = m_font.sampler->sampler(),
            .imageView      = m_font.texture->image_view(),
            .imageLayout    = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL
        };
        
        VqWriteDescriptorSet    descWrite;
        descWrite.dstSet            = m_font.descriptor;
        descWrite.dstBinding        = 0;
        descWrite.descriptorCount   = 1;
        descWrite.descriptorType    = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
        descWrite.pImageInfo        = &imgInfo;
        
        vkUpdateDescriptorSets(m_viz->device(), 1, &descWrite, 0, nullptr);
        
        return true;
    }

    void    ViGui::draw(ViContext&u, Widget*w)
    {
        if(!w)
            return ;
            
        auto r = auto_reset(u.imgui, true);
        ImGui::SetCurrentContext(m_context);
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        w -> imgui_(u);
        ImGui::Render();
    }
    
    bool    ViGui::_import_index(const ImDrawData&dd)
    {
        // No indices... which can be fine
        if(dd.TotalIdxCount <= 0)
            return true;
            
        size_t  cnt     = (size_t) std::max(0, dd.TotalIdxCount);
        m_index.count  = cnt;
        m_index.bytes  = cnt * sizeof(ImDrawIdx);

        if((cnt > m_index.capacity.count) || !m_index.buffer){
            if(m_index.buffer){
                m_viz -> cleanup([buf = std::move(m_index.buffer)](){
                    ViBuffer*   bp  = const_cast<ViBuffer*>(buf.ptr());
                    bp -> kill();
                });
            }
            m_index.capacity    = {};
            
            size_t  cb                  = m_index.bytes;
            cb  = two_alignment(cb, kBufferAlignment) << 1; 
            cb  = std::max(cb, kInitCapacity);
            m_index.capacity.bytes     = cb;
            m_index.capacity.count     = cb / sizeof(ImDrawIdx);
            
            m_index.buffer     = new ViBuffer(*m_viz, cb, VK_BUFFER_USAGE_INDEX_BUFFER_BIT, VMA_MEMORY_USAGE_CPU_TO_GPU);
            if(!m_index.buffer -> valid()){
                vizWarning << "ViGui is unable to allocate index buffer!  (size demanded " << cb << ")";
                return false;
            }
        }
        
        if(m_index.buffer->map() != std::error_code()){
            m_index.buffer = {};       // likely best to jettison and re-try next time
            vizWarning << "ViGui is unable to map index buffer!";
            return false;
        }
        
    
        ImDrawIdx* dst = (ImDrawIdx*) m_index.buffer->data();
        for(int n=0;n<dd.CmdListsCount;++n){
            const ImDrawList&   cmd = *dd.CmdLists[n];
            memcpy(dst, cmd.IdxBuffer.Data, cmd.IdxBuffer.Size*sizeof(ImDrawIdx));
            dst += cmd.IdxBuffer.Size;
        }
        
        m_index.buffer ->unmap();
        return true;
    }
        
    bool    ViGui::_import_vertex(const ImDrawData&dd)
    {
        // No vertices... which can be fine
        if(dd.TotalVtxCount <= 0)
            return true;

        size_t cnt      = (size_t) std::max(0, dd.TotalVtxCount);
        m_vertex.count  = cnt;
        m_vertex.bytes  = cnt * sizeof(ImDrawVert);
        
        if((cnt > m_vertex.capacity.count) || !m_vertex.buffer){
            if(m_vertex.buffer){
                m_viz -> cleanup([buf = std::move(m_vertex.buffer)](){
                    ViBuffer*   bp  = const_cast<ViBuffer*>(buf.ptr());
                    bp -> kill();
                });
            }
        
            m_vertex.capacity   = {};
            
            size_t  cb      = m_vertex.bytes;
            cb  = two_alignment(cb, kBufferAlignment) << 1; 
            cb  = std::max(cb, kInitCapacity);
            
            m_vertex.capacity.bytes     = cb;
            m_vertex.capacity.count     = cb / sizeof(ImDrawVert);
            
        
            m_vertex.buffer     = new ViBuffer(*m_viz, cb, VK_BUFFER_USAGE_VERTEX_BUFFER_BIT, VMA_MEMORY_USAGE_CPU_TO_GPU);
            if(!m_vertex.buffer -> valid()){
                vizWarning << "ViGui is unable to allocate vertex buffer! (size demanded " << cb << ")";
                return false;
            }
        }
        
        if(m_vertex.buffer->map() != std::error_code()){
            m_vertex.buffer = {};       // likely best to jettison and re-try next time
            vizOnceWarning << "ViGui is unable to map vertex buffer!";
            return false;
        }
        
    
        ImDrawVert* dst = (ImDrawVert*) m_vertex.buffer->data();
        for(int n=0;n<dd.CmdListsCount;++n){
            const ImDrawList&   cmd = *dd.CmdLists[n];
            memcpy(dst, cmd.VtxBuffer.Data, cmd.VtxBuffer.Size*sizeof(ImDrawVert));
            dst += cmd.VtxBuffer.Size;
        }
        
        m_vertex.buffer ->unmap();
        return true;
    }


    void    ViGui::record(ViContext&u)
    {
        ImGui::SetCurrentContext(m_context);

        const ImDrawData*   drawData    = ImGui::GetDrawData();
        if(!drawData)
            return ;

        int fb_width = (int)(drawData->DisplaySize.x * drawData->FramebufferScale.x);
        int fb_height = (int)(drawData->DisplaySize.y * drawData->FramebufferScale.y);
        if (fb_width <= 0 || fb_height <= 0)
            return;

        if(m_update(U::Pipeline) || u.pipeline_rebuild || !m_pipeline){
            m_pipeline  = m_viz -> pipeline_create(global().pipeline);
            m_update   -= U::Pipeline;
        }
        
        if(u.pipeline != m_pipeline -> pipeline()){
            u.pipeline          = m_pipeline       -> pipeline();
            u.pipeline_layout   = m_pipelineLayout -> pipeline_layout();
            u.pipeline_shaders  = m_pipelineLayout -> shader_mask();
        }
        
        if(drawData->CmdListsCount <= 0)    // nothing to do
            return ;
    
        if(!_import_vertex(*drawData))
            return;
        if(!_import_index(*drawData))
            return ;
            
        vkCmdBindPipeline(u.command_buffer, VK_PIPELINE_BIND_POINT_GRAPHICS, u.pipeline);
        
        if(m_vertex.count){
            VkBuffer        vbo  = m_vertex.buffer->buffer();
            VkDeviceSize    offset = 0;
            
            vkCmdBindVertexBuffers(u.command_buffer, 0, 1, &vbo, &offset);
            vkCmdBindIndexBuffer(u.command_buffer, m_index.buffer->buffer(), 0, sizeof(ImDrawIdx) == 2 ? VK_INDEX_TYPE_UINT16 : VK_INDEX_TYPE_UINT32);
        }

        VkViewport viewport;
        viewport.x = 0;
        viewport.y = 0;
        viewport.width = (float)fb_width;
        viewport.height = (float)fb_height;
        viewport.minDepth = 0.0f;
        viewport.maxDepth = 1.0f;
        vkCmdSetViewport(u.command_buffer, 0, 1, &viewport);
        
        // Setup scale and translation:
        // Our visible imgui space lies from draw_data->DisplayPps (top left) to draw_data->DisplayPos+data_data->DisplaySize (bottom right). DisplayPos is (0,0) for single viewport apps.
        
        Push    push;
        push.scale.x     = 2.0f / drawData->DisplaySize.x;
        push.scale.y     = 2.0f / drawData->DisplaySize.y;
        push.translate.x = -1.0f - drawData->DisplayPos.x * push.scale.x;
        push.translate.y = -1.0f - drawData->DisplayPos.y * push.scale.y;
        
        vkCmdPushConstants(u.command_buffer, u.pipeline_layout, 
            m_pipelineLayout->shader_mask(), 0, sizeof(push), &push);

        //  Reference
        // ImGui_ImplVulkan_RenderDrawData(ImGui::GetDrawData(), u.command_buffer, nullptr);
        
        ImVec2      clip_off    = drawData->DisplayPos;         // (0,0) unless using multi-viewports
        ImVec2      clip_scale  = drawData->FramebufferScale;   // (1,1) unless using retina display which are often (2,2)

        int         global_vtx_offset = 0;
        int         global_idx_offset = 0;

        for(int n=0;n<drawData->CmdListsCount;++n){
            const ImDrawList&   cmdL = *drawData->CmdLists[n];
            for(int m=0;m<cmdL.CmdBuffer.Size;++m){
                const ImDrawCmd&    cmd = cmdL.CmdBuffer[m];
            
                // Project scissor/clipping rectangles into framebuffer space
                ImVec2 clip_min((cmd.ClipRect.x - clip_off.x) * clip_scale.x, (cmd.ClipRect.y - clip_off.y) * clip_scale.y);
                ImVec2 clip_max((cmd.ClipRect.z - clip_off.x) * clip_scale.x, (cmd.ClipRect.w - clip_off.y) * clip_scale.y);

                // Clamp to viewport as vkCmdSetScissor() won't accept values that are off bounds
                if (clip_min.x < 0.0f) { clip_min.x = 0.0f; }
                if (clip_min.y < 0.0f) { clip_min.y = 0.0f; }
                if (clip_max.x > fb_width) { clip_max.x = (float)fb_width; }
                if (clip_max.y > fb_height) { clip_max.y = (float)fb_height; }
                if (clip_max.x <= clip_min.x || clip_max.y <= clip_min.y)
                    continue;

                // Apply scissor/clipping rectangle
                VkRect2D scissor;
                scissor.offset.x = (int32_t)(clip_min.x);
                scissor.offset.y = (int32_t)(clip_min.y);
                scissor.extent.width = (uint32_t)(clip_max.x - clip_min.x);
                scissor.extent.height = (uint32_t)(clip_max.y - clip_min.y);
                vkCmdSetScissor(u.command_buffer, 0, 1, &scissor);

                VkDescriptorSet desc_set = m_font.descriptor;

#if 0
                // Bind DescriptorSet with font or user texture
                if constexpr (sizeof(ImTextureID) < sizeof(ImU64)) {
                    desc_set    = m_font.descriptor;
                } else {
                    desc_set    = (VkDescriptorSet) cmd.TextureId;
                }
                if(!desc_set){
                    desc_set    = m_font.descriptor;
                }
                
                if(!desc_set)
                    vizWarning << "Texture descriptor is NULL!";
#endif

                vkCmdBindDescriptorSets(u.command_buffer, VK_PIPELINE_BIND_POINT_GRAPHICS, u.pipeline_layout, 0, 1, &desc_set, 0, nullptr);

                // Draw
                vkCmdDrawIndexed(u.command_buffer, cmd.ElemCount, 1, cmd.IdxOffset + global_idx_offset, cmd.VtxOffset + global_vtx_offset, 0);
            }
            global_idx_offset += cmdL.IdxBuffer.Size;
            global_vtx_offset += cmdL.VtxBuffer.Size;
        }


    //  Restore the scissors to back to a full viewport
        VkRect2D scissor = { { 0, 0 }, { (uint32_t)fb_width, (uint32_t)fb_height } };
        vkCmdSetScissor(u.command_buffer, 0, 1, &scissor);
    }

    void    ViGui::update(UpdateFlags flags)
    {
        ImGui::SetCurrentContext(m_context);

        m_update |= flags;
        if(m_update(U::Font)){
            if(!_font_update()){
                m_update |= U::Font;
                return ;
            }
            m_update -= U::Font;
        }
    }

    bool    ViGui::valid() const
    {
        return m_viz && m_viz -> device() && m_context;
    }
}

