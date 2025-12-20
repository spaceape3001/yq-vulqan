////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/vulkan/ViGui.hpp>

#include <yq/resource/Resource.hpp>
#include <yq/resource/ResourceIO.hpp>
#include <yq/core/StreamOps.hpp>
#include <yq/file/FileResolver.hpp>
#include <yq/math/integer.hpp>
#include <yq/raster/Painter2.hpp>
#include <yq/raster/Pixels.hxx>
#include <yq/stream/Text.hpp>
#include <yq/text/format.hpp>
#include <yq/util/AutoReset.hpp>
#include <yq/util/Safety.hpp>

#include <yq/tachyon/logging.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/asset/Raster.hpp>
#include <yq/tachyon/pipeline/Pipeline.hpp>
#include <yq/tachyon/pipeline/PipelineWriter.hpp>
#include <yq/tachyon/asset/Sampler.hpp>
#include <yq/tachyon/asset/Shader.hpp>
#include <yq/tachyon/asset/Texture.hpp>
#include <yq/tachyon/api/Widget.hpp>
#include <yq/tachyon/app/ViewerState.hpp>
#include <yq/tachyon/event/keyboard/KeyCharacterEvent.hpp>
#include <yq/tachyon/event/keyboard/KeyPressEvent.hpp>
#include <yq/tachyon/event/keyboard/KeyReleaseEvent.hpp>
#include <yq/tachyon/event/mouse/MouseMoveEvent.hpp>
#include <yq/tachyon/event/mouse/MousePressEvent.hpp>
#include <yq/tachyon/event/mouse/MouseReleaseEvent.hpp>
#include <yq/tachyon/event/ui/DefocusEvent.hpp>
#include <yq/tachyon/event/ui/FocusEvent.hpp>
#include <yq/tachyon/vulkan/VqStructs.hpp>
#include <yq/tachyon/vulkan/ViBuffer.hpp>
#include <yq/tachyon/vulkan/ViContext.hpp>
#include <yq/tachyon/vulkan/ViDevice.hpp>
#include <yq/tachyon/vulkan/ViImage.hpp>
#include <yq/tachyon/vulkan/ViLogging.hpp>
#include <yq/tachyon/vulkan/ViManager.hpp>
#include <yq/tachyon/vulkan/ViPipeline.hpp>
#include <yq/tachyon/vulkan/ViPipelineLayout.hpp>
#include <yq/tachyon/vulkan/ViSampler.hpp>
#include <yq/tachyon/vulkan/ViSwapchain.hpp>
#include <yq/tachyon/vulkan/ViTexture.hpp>
#include <yq/tachyon/vulkan/ViVisualizer.hpp>


//#include <backends/imgui_impl_glfw.h>

#include <atomic>

//  for debugging....
#include <fstream>

/*
    This file leans heavily on imgui_impl_vulkan.cpp for patterns, some code is 
    copied.  As we're basically leaning into our vulkan engine instead.
*/

namespace yq::tachyon {

    #define CTX_PRESERVE                                            \
        auto _reset = safety([old=ImGui::GetCurrentContext()](){    \
            ImGui::SetCurrentContext(old);                          \
        });


    static constexpr const size_t   kInitCapacity     = 8192;
    static constexpr const size_t   kBufferAlignment  = 256;
    static constexpr const unsigned kAutoEraseTextures    = 10;
    
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
        p -> shaders({"yq/imgui/vigui.vert", "yq/imgui/vigui.frag" });
        p -> culling(CullMode::None);
        p -> polygons(PolygonMode::Fill);
        p -> front(FrontFace::CounterClockwise);
        p -> wireframe_permitted(false);
        
        p -> vertex<ImDrawVert>({.activity=REFRESH})
                .attribute(&ImDrawVert::pos, DataFormat::R32G32_SFLOAT)
                .attribute(&ImDrawVert::uv, DataFormat::R32G32_SFLOAT)
                .attribute(&ImDrawVert::col, DataFormat::R8G8B8A8_UNORM)  // SRGB crashes/freezes the code!
        ;
        p -> index<ImDrawIdx>({.activity=REFRESH});
        p -> texture({.activity=REFRESH});
        p -> topology(Topology::TriangleList);
        
        p -> push<Push>();
        
        p -> color_blending(ColorBlend::AlphaBlend);
        
        font.sampler = new Sampler({
            .flags  = {},
            .magFilter  = SamplerFilter::Linear,
            .minFilter  = SamplerFilter::Linear,
            .mipmapMode = SamplerMipmapMode::Linear,
            .addressMode = SamplerAddressModeUVW(ALL, SamplerAddressMode::Repeat),
            .maxAnisotropy  = 1.0f,
            .minLod = -1000,
            .maxLod = 1000,
            .unnormalizedCoordinates = false
        });
        
        //font.texInfo.swizzle = { ComponentSwizzle::Alpha, ComponentSwizzle::Alpha, ComponentSwizzle::Alpha, ComponentSwizzle::Alpha };
        
        //font.texInfo.
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

    ViGui::ViGui(ViVisualizer& viz, const Options& options) : m_viz(&viz)
    {
        if(!_init(options)){
            _kill();
        }
    }
    
    ViGui::~ViGui()
    {
        _kill();
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
                m_viz -> device(REF).cleanup([buf = std::move(m_index.buffer)](){
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
            
            m_index.buffer     = new ViBuffer(m_viz->device(REF), cb, VK_BUFFER_USAGE_INDEX_BUFFER_BIT, VMA_MEMORY_USAGE_CPU_TO_GPU);
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
        
        if(m_update(U::Index)){
            if(cnt){
                m_index.data.resize(cnt, 0);
                dst = m_index.data.data();
                for(int n=0;n<dd.CmdListsCount;++n){
                    const ImDrawList&   cmd = *dd.CmdLists[n];
                    memcpy(dst, cmd.IdxBuffer.Data, cmd.IdxBuffer.Size*sizeof(ImDrawIdx));
                    dst += cmd.IdxBuffer.Size;
                }
            } else {
                m_index.data.clear();
            }
            m_update -= U::Index;
        }
        
        m_index.buffer ->unmap();
        return true;
    }

    void    ViGui::_import_texture(ImTextureData* tex)
    {
        G&  g   = global();

        int width   = tex->Width;
        int height  = tex->Height;
        int bpp     = tex->BytesPerPixel;
        
        if(width <= 0)
            return ;
        if(height <= 0)
            return ;
        if(!tex->Pixels)
            return;

        RasterInfo      imgInfo;
        imgInfo.size.x      = (unsigned) width;
        imgInfo.size.y      = (unsigned) height;
        
        switch(bpp){
        case 1:
            imgInfo.format  = DataFormat::R8_UNORM;
            break;
        case 3:
            imgInfo.format  = DataFormat::R8G8B8_UNORM;
            break;
        case 4:
            imgInfo.format      = DataFormat::R8G8B8A8_UNORM;
            break;
        default:
            return;
        }

        size_t      bytes   = (size_t) width * (size_t) height * (size_t) bpp;
        RasterCPtr  img     = new Raster(imgInfo, Memory(COPY, tex->Pixels, bytes));
        TextureCPtr texp    = new Texture(img, g.font.sampler, g.font.texInfo);
        
        auto& tt    = m_textures[texp->id()];
        tt.image    = img;
        tt.texture  = texp;
        tex->TexID  = texp->id();
        
        _init(tt);
        _update(tt);

        tex->SetStatus(ImTextureStatus_OK);
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
                m_viz -> device(REF).cleanup([buf = std::move(m_vertex.buffer)](){
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
        
            m_vertex.buffer     = new ViBuffer(m_viz->device(REF), cb, VK_BUFFER_USAGE_VERTEX_BUFFER_BIT, VMA_MEMORY_USAGE_CPU_TO_GPU);
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

        if(m_update(U::Vertex)){
            if(cnt){
                m_vertex.data.resize(cnt);
                dst = m_vertex.data.data();
                for(int n=0;n<dd.CmdListsCount;++n){
                    const ImDrawList&   cmd = *dd.CmdLists[n];
                    memcpy(dst, cmd.VtxBuffer.Data, cmd.VtxBuffer.Size*sizeof(ImDrawVert));
                    dst += cmd.VtxBuffer.Size;
                }
            } else {
                m_vertex.data.clear();
            }
            m_update -= U::Vertex;
        }

        m_vertex.buffer ->unmap();

        return true;
    }

    bool    ViGui::_init(const Options& options)
    {
        G&  g   = global();

        CTX_PRESERVE
        m_context   = ImGui::CreateContext();
        ImGui::SetCurrentContext(m_context);
        
        ImGuiIO& io = ImGui::GetIO();
        io.IniFilename              = nullptr;  // Disable INI settings (to file)
        
        io.BackendRendererName      = "yq::tachyon::ViGui";
        io.BackendRendererUserData  = this;
        io.BackendFlags |= ImGuiBackendFlags_RendererHasVtxOffset;  // We can honor the ImDrawCmd::VtxOffset field, allowing for large meshes.
        
        io.BackendPlatformUserData  = this;
        io.BackendPlatformName      = "yq::tachyon::ViGui";

        m_pipeline                  = m_viz -> pipeline_create(g.pipeline);
        if(!m_pipeline){
            imguiWarning << "Unable to create pipeline!";
            return false;
        }
        
        m_pipelineLayout            = m_pipeline -> layout();
        m_descriptorPool            = m_viz->descriptor_pool();;
        
        //m_font.sampler          = m_viz -> sampler_create(*g.font.sampler);
        
        m_descriptorLayout          = m_pipelineLayout -> descriptor_set_layout();

        // Current hack to upscale fonts (need to load it)
        io.FontGlobalScale = 1.25f;
        io.Fonts->AddFontDefault();
        
        io.Fonts->Build();
        if(!io.Fonts->IsBuilt()){
            imguiWarning << "Fonts are NOT built, there's going to be problems.";
        }

        return true;
    }

    bool    ViGui::_init(T& t)
    {
        VqDescriptorSetAllocateInfo allocInfo;
        allocInfo.descriptorPool        = m_descriptorPool;
        allocInfo.descriptorSetCount    = 1;
        allocInfo.pSetLayouts           = &m_descriptorLayout;
        
        VkResult    res = vkAllocateDescriptorSets(m_viz->device(), &allocInfo, &t.descriptor);
        if(res != VK_SUCCESS){
            imguiWarning << "Unable to allocate descriptor sets.  VkResult " << (int32_t) res;
            return false;
        }
        return true;
    }

    bool    ViGui::_init(T& t, const TextureCPtr& tex)
    {
        if(!_init(t))
            return false;
        t.texture       = tex;
        return _update(t);
    }
    
    void    ViGui::_kill()
    {
        if(m_context){
            {
                CTX_PRESERVE
                ImGui::SetCurrentContext(m_context);
                //ImGui_ImplGlfw_Shutdown();

                ImGuiIO& io = ImGui::GetIO();
                io.BackendRendererName      = nullptr;
                io.BackendRendererUserData  = nullptr;
                io.BackendPlatformName      = nullptr;
                io.BackendPlatformUserData  = nullptr;

                io.BackendFlags            &= ~(ImGuiBackendFlags_RendererHasVtxOffset);
            }
            ImGui::DestroyContext(m_context);
            m_context           = nullptr;
        }

        for(auto& itr : m_textures)
            _kill(itr.second);
        m_textures.clear();

        //_kill(m_font);
        
        m_pipeline              = {};
        m_pipelineLayout        = {};
        m_viz                   = nullptr;

    }
    
    void    ViGui::_kill(T& t)
    {
        if(t.descriptor){
            vkFreeDescriptorSets(m_viz->device(), m_descriptorPool, 1, &t.descriptor);
            t.descriptor        = nullptr;
        }
        t = {};
    }

    bool    ViGui::_update(T&t)
    {
        ViTextureCPtr  vtex = m_viz -> device(REF).texture_create(*t.texture);
        if(!vtex)
            return false;
        
        VkDescriptorImageInfo   descImgInfo {
            .sampler        = vtex->sampler(),
            .imageView      = vtex->image_view(),
            .imageLayout    = VK_IMAGE_LAYOUT_SHADER_READ_ONLY_OPTIMAL
        };

        VqWriteDescriptorSet    descWrite;
        descWrite.dstSet            = t.descriptor;
        descWrite.dstBinding        = 0;
        descWrite.descriptorCount   = 1;
        descWrite.descriptorType    = VK_DESCRIPTOR_TYPE_COMBINED_IMAGE_SAMPLER;
        descWrite.pImageInfo        = &descImgInfo;
        
        vkUpdateDescriptorSets(m_viz->device(), 1, &descWrite, 0, nullptr);
        return true;
    }

    bool    ViGui::_update(T&t, const TextureCPtr& tex)
    {
        if(t.texture)
            m_viz -> device(REF).texture_erase(t.texture->id());
        return _update(t);
    }

    void    ViGui::_write_csv(const ImDrawData&dd, std::string_view pfx)
    {
        std::string     vfile = std::string(pfx) + "vertex.csv";
        _write_csv_vertex(dd, vfile);
        std::string     ifile = std::string(pfx) + "index.csv";
        _write_csv_index(dd, ifile);
    }

    void    ViGui::_write_csv_index(const ImDrawData&dd, std::string_view filename)
    {
        std::ofstream   fidx(std::string(filename), std::ios_base::out | std::ios_base::trunc);
        fidx << "index,vertex,x,y,u,v,red,green,blue,alpha\n";
        for(size_t n=0;n<m_index.data.size();++n){
            ImDrawIdx    val = m_index.data[n];
            if(val >= m_vertex.data.size())
                continue;
                
            const auto&  vtx = m_vertex.data[val];
            ImVec4  clr = ImGui::ColorConvertU32ToFloat4(vtx.col);
            fidx << n << "," << val << "," << vtx.pos.x << "," << vtx.pos.y << "," << vtx.uv.x << "," << vtx.uv.y << "," 
                << clr.x << "," << clr.y << "," << clr.z << "," << clr.w << "\n";
        }
        fidx.close();
    }

    void    ViGui::_write_csv_vertex(const ImDrawData&dd, std::string_view filename)
    {
        std::ofstream   fvtx(std::string(filename), std::ios_base::out | std::ios_base::trunc);
        fvtx << "vertex,x,y,u,v,red,green,blue,alpha\n";
        for(size_t n=0;n<m_vertex.data.size();++n){
            const auto&  vtx = m_vertex.data[n];
            ImVec4  clr = ImGui::ColorConvertU32ToFloat4(vtx.col);
            fvtx << n << "," << vtx.pos.x << "," << vtx.pos.y << "," << vtx.uv.x << "," << vtx.uv.y << "," 
                << clr.x << "," << clr.y << "," << clr.z << "," << clr.w << "\n";
        }
        fvtx.close();
    }
    
    void    ViGui::draw(ViContext&u, Widget*w)
    {
        if(!w)
            return ;
            
        auto r = auto_reset(u.imgui, this);

        CTX_PRESERVE
        ImGui::SetCurrentContext(m_context);
        
        //  Do updates here...
        
        //ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();
        w -> imgui(u);
        ImGui::Render();
        m_update |= U::DrawList;
    }
    

    void    ViGui::prerecord(ViContext&u)
    {

        update();
        
        CTX_PRESERVE
        ImGui::SetCurrentContext(m_context);

        const ImDrawData*   drawData    = ImGui::GetDrawData();
        if(!drawData)
            return ;

        if (drawData->Textures != nullptr){
            for (ImTextureData* tex : *drawData->Textures){
                switch(tex->Status){
                case ImTextureStatus_OK:
                    break;
                case ImTextureStatus_WantCreate:
                    _import_texture(tex);
                    break;
                case ImTextureStatus_WantUpdates:
                    _import_texture(tex);
                    break;
                case ImTextureStatus_WantDestroy:
                case ImTextureStatus_Destroyed:
                    tex -> TexID    = 0;
                    break;
                }
            }
        }
        
        for(auto itr = m_textures.begin(); itr != m_textures.end(); ){
            if(!itr->first){        // it's the NULL, will be here unless all goes well
                ++itr;
            } else if(itr->second.seen){
                itr->second.seen    = false;
                ++(itr->second.stale);
                ++itr;
            } else if(++(itr->second.stale) < kAutoEraseTextures){ 
                ++itr;
            } else {
                _kill(itr->second);
                itr = m_textures.erase(itr);
            }
        }
    }

    void    ViGui::record(ViContext&u)
    {
        CTX_PRESERVE
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
        
        
        if(m_update(U::DrawList)){
            if(drawData->CmdListsCount <= 0)    // nothing to do
                return ;
            if(!_import_vertex(*drawData))
                return;
            if(!_import_index(*drawData))
                return ;
            m_update -= U::DrawList;
        }

        vkCmdBindPipeline(u.command_buffer, VK_PIPELINE_BIND_POINT_GRAPHICS, u.pipeline);
        
        if(m_vertex.count){
            VkBuffer        vbo  = m_vertex.buffer->buffer();
            VkDeviceSize    offset = 0;
            
            vkCmdBindVertexBuffers(u.command_buffer, 0, 1, &vbo, &offset);
            vkCmdBindIndexBuffer(u.command_buffer, m_index.buffer->buffer(), 0, (sizeof(ImDrawIdx) == 2) ? 
                VK_INDEX_TYPE_UINT16 : VK_INDEX_TYPE_UINT32);
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

                uint64_t        texID   = 0UL;
                if(cmd.TexRef._TexData)
                    texID       = cmd.TexRef._TexData -> TexID;
                else
                    texID       = cmd.TexRef._TexID;

                auto& tex = m_textures[texID];
                if(!tex.descriptor){
                    vizFirstWarning(texID) << "Texture descriptor is NULL!";
                    continue;
                }
                tex.seen    = true;


                vkCmdBindDescriptorSets(u.command_buffer, VK_PIPELINE_BIND_POINT_GRAPHICS, u.pipeline_layout, 0, 1, &tex.descriptor, 0, nullptr);

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

    TextureID ViGui::texture(const TextureCPtr&tex)
    {
        if(!tex)
            return {};

        auto itr = m_textures.find(tex->id());
        if(itr != m_textures.end())
            return { tex->id() };
            
        T   tmp;
        if(!_init(tmp, tex))
            return {};
        m_textures[tex->id()] = tmp;
        return { tex->id() };
    }

    void    ViGui::update(UpdateFlags flags)
    {
        CTX_PRESERVE
        ImGui::SetCurrentContext(m_context);

        m_update |= flags;
        //if(m_update(U::Font)){
            //if(!_font_update()){
                //m_update |= U::Font;
                //return ;
            //}
            //m_update -= U::Font;
        //}
    }

    bool    ViGui::valid() const
    {
        return m_viz && m_viz -> device() && m_context;
    }

    ///////////////////////////////////

    void ViGui::update_modifiers(ModifierKeys mk)
    {
        ImGuiIO& io = ImGui::GetIO();
        ModifierKeys    diff    = m_modifiers ^ mk;
        m_modifiers = mk;
        if(has_alt(diff)){
            io.AddKeyEvent(ImGuiMod_Alt, has_alt(mk));
        }
        
        if(has_control(diff)){
            io.AddKeyEvent(ImGuiMod_Ctrl, has_control(mk));
        }
        
        if(has_shift(diff)){
            io.AddKeyEvent(ImGuiMod_Shift, has_shift(mk));
        }
        
        if(has_super(diff)){
            io.AddKeyEvent(ImGuiMod_Super, has_super(mk));
        }
    }

    void ViGui::on(const KeyCharacterEvent&evt)
    {
        CTX_PRESERVE
        ImGui::SetCurrentContext(m_context);
        ImGuiIO& io = ImGui::GetIO();
        io.AddInputCharacter((unsigned int) evt.code());
    }
    
    
    void ViGui::on(const KeyPressEvent&evt)
    {
        ImGuiKey ik  = (ImGuiKey) encode_imgui(evt.key());
        if(ik < 0)
            return ;
    
        CTX_PRESERVE
        ImGui::SetCurrentContext(m_context);

        update_modifiers(evt.modifiers());
        ImGuiIO& io = ImGui::GetIO();
        io.AddKeyEvent(ik, true);
    }
    
    void ViGui::on(const KeyReleaseEvent&evt)
    {
        ImGuiKey ik  = (ImGuiKey) encode_imgui(evt.key());
        if(ik < 0)
            return ;

        CTX_PRESERVE
        ImGui::SetCurrentContext(m_context);

        update_modifiers(evt.modifiers());
        ImGuiIO& io = ImGui::GetIO();
        io.AddKeyEvent(ik, false);
    }
    
    void ViGui::on(const MouseMoveEvent&evt)
    {
        CTX_PRESERVE
        ImGui::SetCurrentContext(m_context);
        update_modifiers(evt.modifiers());
        ImGuiIO& io = ImGui::GetIO();
        io.AddMousePosEvent(evt.x(), evt.y());
        m_mouse = evt.position();
    }
    
    void ViGui::on(const MousePressEvent&evt)
    {
        CTX_PRESERVE
        ImGui::SetCurrentContext(m_context);
        update_modifiers(evt.modifiers());
        ImGuiIO& io = ImGui::GetIO();
        int b   = (int) evt.button().value();
        if((b >= 0) && (b < ImGuiMouseButton_COUNT)){
            io.AddMouseButtonEvent(b, true);
        }
        m_mouse = evt.position();
    }
    
    void ViGui::on(const MouseReleaseEvent&evt)
    {
        CTX_PRESERVE
        ImGui::SetCurrentContext(m_context);
        update_modifiers(evt.modifiers());
        ImGuiIO& io = ImGui::GetIO();
        int b   = (int) evt.button().value();
        if((b >= 0) && (b < ImGuiMouseButton_COUNT)){
            io.AddMouseButtonEvent(b, false);
        }
        m_mouse = evt.position();
    }

    void    ViGui::on(const DefocusEvent&)
    {
        CTX_PRESERVE
        ImGui::SetCurrentContext(m_context);
        ImGuiIO& io = ImGui::GetIO();
        io.AddFocusEvent(false);
    }
    
    void    ViGui::on(const FocusEvent&)
    {
        CTX_PRESERVE
        ImGui::SetCurrentContext(m_context);
        ImGuiIO& io = ImGui::GetIO();
        io.AddFocusEvent(true);
    }

    void    ViGui::tick(const ViewerState&state)
    {
        CTX_PRESERVE
        ImGui::SetCurrentContext(m_context);
        ImGuiIO& io = ImGui::GetIO();

        // update the area
        io.DisplaySize  = ImVec2((float) state.window.area.x, (float) state.window.area.y);
        if((state.window.area.x > 0) && (state.window.area.y > 0)){
            io.DisplayFramebufferScale  = ImVec2(
                (float) state.window.pixels.x / (float) state.window.area.x,
                (float) state.window.pixels.y / (float) state.window.area.y
            );
        }
        
        // update the time
        double  curtime = std::max(state.time, m_time+0.00001f);
        io.DeltaTime = (m_time>0.) ? (float)(curtime - m_time) : (float)(1.f/60.f);
        m_time = curtime;
        
        // update mouse position
        io.AddMousePosEvent((float) state.mouse.position.x, (float) state.mouse.position.y);
    }
    

    ///////////////////////////////////
    //void ViGui::init_meta()
    //{
        //auto w = writer<ViGui>();
        //w.description("ImGui Visualization");
        //w.receive(&ViGui::key_character_event);
        //w.receive(&ViGui::key_press_event);
        //w.receive(&ViGui::key_release_event);
        //w.receive(&ViGui::mouse_move_event);
        //w.receive(&ViGui::mouse_press_event);
        //w.receive(&ViGui::mouse_release_event);
        //w.receive(&ViGui::window_defocus_event);
        //w.receive(&ViGui::window_focus_event);
        //w.receive(&ViGui::window_state_event);
    //}
}


