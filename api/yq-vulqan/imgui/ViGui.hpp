////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-toolbox/keywords.hpp>
#include <yq-toolbox/basic/Flags.hpp>
#include <yq-toolbox/basic/Ref.hpp>
#include <yq/typedef/filesystem_path.hpp>

#include <yq-vulqan/imgui/MyImGui.hpp>
#include <yq-vulqan/typedef/buffer.hpp>
#include <yq-vulqan/typedef/image.hpp>
#include <yq-vulqan/typedef/pipeline.hpp>
#include <yq-vulqan/typedef/pipeline_layout.hpp>
#include <yq-vulqan/typedef/sampler.hpp>
#include <yq-vulqan/typedef/texture.hpp>

#include <vk_mem_alloc.h>
#include <initializer_list>

struct ImFont;
struct ImDrawData;
struct ImDrawList;
struct ImGuiContext;

namespace yq::tachyon {
    class ViVisualizer;
    struct ViContext;
    class Widget;

    struct ViGuiOptions {
    };

    class ViGui {
    public:
    
        enum class U : uint8_t {
            Font,
            Pipeline
        };
        
        using UpdateFlags = Flags<U>;
    
        ViGui(ViVisualizer&, const ViGuiOptions& options={});
        ~ViGui();
        
        ImGuiContext*   context() const { return m_context; }
        
        void    update(UpdateFlags={});
        
        void    draw(ViContext&, Widget*);
        
        void    record(ViContext&);
        
        bool    valid() const;
        
        
    private:
    
        bool    _init(const ViGuiOptions&);
        void    _kill();
    
        ViGui(const ViGui&) = delete;
        ViGui(ViGui&&) = delete;
        ViGui& operator=(const ViGui&) = delete;
        ViGui& operator=(ViGui&&) = delete;
    
        struct G;
        static G&           global();
    
        ViVisualizer*           m_viz       = nullptr;
        ImGuiContext*           m_context   = nullptr;
        ViPipelineCPtr          m_pipeline;
        ViPipelineLayoutCPtr    m_pipelineLayout;
        //! Forced updates
        UpdateFlags             m_update    = {};
        
        struct Push;
        
        struct T {
            VkDescriptorSet     descriptor  = nullptr;
            VkDescriptorPool    descPool    = nullptr;
            ImageCPtr           image;
            TextureCPtr         texture;
        }  m_font;
        
        struct Z {
            size_t          count   = 0;
            size_t          bytes   = 0;
        };
        
        struct B : public Z {
            Z               capacity;
            ViBufferPtr     buffer;
        }                   m_vertex, m_index;
        
        bool            _font_update();
        const ImFont*   _font_load(const std::filesystem::path&, float pixel_size=0);
        void            _descriptor_write();
        
        bool            _import_vertex(const ImDrawData&);
        bool            _import_index(const ImDrawData&);
    };
}
