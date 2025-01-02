////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/keywords.hpp>
#include <yq/core/Flags.hpp>
#include <yq/core/Ref.hpp>
#include <yq/vector/Vector2.hpp>
#include <yq/typedef/filesystem_path.hpp>

#include <yq/tachyon/MyImGui.hpp>
#include <yq/tachyon/api/Tachyon.hpp>
#include <yt/os/ModifierKey.hpp>
#include <yt/typedef/buffer.hpp>
#include <yq/tachyon/typedef/events.hpp>
#include <yt/typedef/pipeline.hpp>
#include <yq/tachyon/typedef/vi_buffer.hpp>
#include <yq/tachyon/typedef/vi_pipeline.hpp>
#include <yq/tachyon/typedef/vi_pipeline_layout.hpp>
#include <yt/typedef/raster.hpp>
#include <yt/typedef/sampler.hpp>
#include <yt/typedef/texture.hpp>

#include <vk_mem_alloc.h>
#include <initializer_list>

//struct ImFont;
//struct ImDrawData;
//struct ImDrawList;
//struct ImDrawVert;
//struct ImGuiContext;

namespace yq::tachyon {
    class ViVisualizer;
    struct ViContext;
    class Widget;
    
    class KeyCharacterEvent;
    class KeyPressEvent;
    class KeyReleaseEvent;
    class MousePressEvent;
    class MouseMoveEvent;
    class MouseReleaseEvent;
    class WindowFocusEvent;
    class WindowDefocusEvent;
    
    struct ViewerState;
    
    //class 

    class ViGui {
    public:
    
        enum class U : uint8_t {
            Font,
            Pipeline,
            DrawList,
            
            //! Update vertex list
            Vertex,
            //! Update index list
            Index
        };
        
        using UpdateFlags = Flags<U>;
        
        struct Options {
        };
    
        ViGui(ViVisualizer&, const Options& options={});
        ~ViGui();
        
        ImGuiContext*   context() const { return m_context; }
        
        void    update(UpdateFlags={});
        
        void    draw(ViContext&, Widget*);
        
        void    record(ViContext&);
        
        bool    valid() const;
        
        static void init_info();
        
        void    tick(const ViewerState&);
        
        
    private:
    
        bool    _init(const Options&);
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
        ModifierKeys            m_modifiers;
        Vector2D                m_mouse;
        double                  m_time = 0.;
        
        struct Push;
        
        struct T {
            VkDescriptorSet     descriptor  = nullptr;
            VkDescriptorPool    descPool    = nullptr;
            RasterCPtr          image;
            TextureCPtr         texture;
        }  m_font;
        
        struct Z {
            size_t          count   = 0;
            size_t          bytes   = 0;
        };
        
        struct V : public Z {
            Z                       capacity;
            ViBufferPtr             buffer;
            std::vector<ImDrawVert> data;
        }                           m_vertex;
        
        struct I : public Z {
            Z                       capacity;
            ViBufferPtr             buffer;
            std::vector<ImDrawIdx>  data;
        }                   m_index;
        
        bool            _font_update();
        const ImFont*   _font_load(const std::filesystem::path&, float pixel_size=0);
        void            _descriptor_write();
        
        bool            _import_vertex(const ImDrawData&);
        bool            _import_index(const ImDrawData&);
        
        void            _write_csv(const ImDrawData&, std::string_view pfx="imgui-");
        void            _write_csv_vertex(const ImDrawData&, std::string_view filename);
        void            _write_csv_index(const ImDrawData&, std::string_view filename);

        void    update_modifiers(ModifierKeys);
    public:
    
        void    on(const MouseMoveEvent&);
        void    on(const MousePressEvent&);
        void    on(const MouseReleaseEvent&);
        
        void    on(const KeyPressEvent&);
        void    on(const KeyReleaseEvent&);
        void    on(const KeyCharacterEvent&);
        
        void    on(const WindowFocusEvent&);
        void    on(const WindowDefocusEvent&);
//        void    on(const WindowStateEvent&);
    };
    
    #if 0
    //  For ImGuiTextures, need to have some sort of system for widgets to register
    class MyGuiTexture {
        void    inc_ref();
        void    dec_ref();
    };
    #endif
}
