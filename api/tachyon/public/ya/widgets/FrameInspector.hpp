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
    
    class FrameInspectorHeader;
    class FrameInspector : public Widget {
        YQ_TACHYON_DECLARE(FrameInspector, Widget)
    public:
        FrameInspector();
        ~FrameInspector();
        
        virtual void    imgui(ViContext&);
        
        Execution setup(const Context&) override;
        
        static void init_info();

    private:
    
        class Tachyons;
        class Widgets;
        class Windows;
        class Viewers;
        
        const Frame*    m_frame     = nullptr;

        FrameInspectorHeader*   m_header    = nullptr;
        Tachyons*       m_tachyons  = nullptr;
        Widgets*        m_widgets   = nullptr;
        Windows*        m_windows   = nullptr;
        Viewers*        m_viewers   = nullptr;
        
    
        TextLabel*  m_la1;
    };
}
