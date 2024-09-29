////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViGui.hpp"
#include <yq-toolbox/basic/DelayInit.hpp>
#include <yq-toolbox/io/FileResolver.hpp>

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

namespace yq::tachyon {

    static constexpr const size_t kInitCapacity    = 8192;

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
        
        p -> vertex<ImDrawVert>(REFRESH)
                .attribute(&ImDrawVert::pos, DataFormat::R32G32_SFLOAT)
                .attribute(&ImDrawVert::uv, DataFormat::R32G32_SFLOAT)
                .attribute(&ImDrawVert::col, DataFormat::R8G8B8A8_UNORM)
        ;
        p -> push<glm::vec4>();
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
        
        ImGuiIO& io = ImGui::GetIO();
        io.BackendRendererName      = "yq::tachyon::ViGui";
        io.BackendRendererUserData  = this;
        io.BackendFlags |= ImGuiBackendFlags_RendererHasVtxOffset;  // We can honor the ImDrawCmd::VtxOffset field, allowing for large meshes.
        
        m_pipelineLayout        = new ViPipelineLayout(*m_viz, g.pipeline);
        m_pipeline              = new ViPipeline(*m_viz, m_pipelineLayout, g.pipeline_options);
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
        if(m_context){
            ImGui::SetCurrentContext(m_context);
            ImGuiIO& io = ImGui::GetIO();
            io.BackendRendererName      = nullptr;
            io.BackendRendererUserData  = nullptr;
            io.BackendFlags            &= ~ImGuiBackendFlags_RendererHasVtxOffset;
            ImGui::DestroyContext(m_context);
            m_context           = nullptr;
        }
        
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

    void    ViGui::record(ViContext&u)
    {
        static G&  g   = global();
        if(m_update(U::Pipeline) || u.pipeline_rebuild || !m_pipeline){
            m_pipeline  = new ViPipeline(*m_viz, m_pipelineLayout, g.pipeline_options);
            m_update   -= U::Pipeline;
        }
        
        if(u.pipeline != m_pipeline -> pipeline()){
            u.pipeline          = m_pipeline       -> pipeline();
            u.pipeline_layout   = m_pipelineLayout -> pipeline_layout();
            u.pipeline_shaders  = m_pipelineLayout -> shader_mask();
        }
        
        
        
    }

    bool    ViGui::valid() const
    {
        return m_viz && m_viz -> device() && m_context;
    }
}

