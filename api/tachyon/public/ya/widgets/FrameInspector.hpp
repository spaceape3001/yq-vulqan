////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/ui/Widget.hpp>

namespace yq::tachyon {
    class Frame;
    class TextLabel;
    
    class FrameInspector : public Widget {
        YQ_TACHYON_DECLARE(FrameInspector, Widget)
    public:
        FrameInspector();
        ~FrameInspector();
        
        virtual void    imgui(ViContext&);
        
        Execution setup(const Context&) override;
        
        static void init_info();
        
        class Sub;

    private:
        
        Ref<const Frame>    m_frame;
        std::vector<Sub*>   m_subs;

        Widget*     m_header        = nullptr;
        Widget*     m_cameras       = nullptr;
        Widget*     m_camera³s      = nullptr;
        Widget*     m_controllers   = nullptr;
        Widget*     m_cursors       = nullptr;
        Widget*     m_desktops      = nullptr;
        Widget*     m_joysticks     = nullptr;
        Widget*     m_keyboards     = nullptr;
        Widget*     m_lights        = nullptr;
        Widget*     m_light³s       = nullptr;
        Widget*     m_managers      = nullptr;
        Widget*     m_models        = nullptr;
        Widget*     m_monitors      = nullptr;
        Widget*     m_mouses        = nullptr;
        Widget*     m_rendereds     = nullptr;
        Widget*     m_rendered³s    = nullptr;
        Widget*     m_scenes        = nullptr;
        Widget*     m_scene³s       = nullptr;
        Widget*     m_spatials      = nullptr;
        Widget*     m_spatial³s     = nullptr;
        Widget*     m_tachyons      = nullptr;
        Widget*     m_threads       = nullptr;
        Widget*     m_viewers       = nullptr;
        Widget*     m_widgets       = nullptr;
        Widget*     m_windows       = nullptr;
        
        bool        m_track         = true;
        bool        m_init          = false;
        
        template <typename F>
        void        make(Widget*&);
    };
}
