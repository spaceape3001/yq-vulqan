////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/ui/Widget.hpp>

namespace yq::tachyon {
    class TextLabel;
    class FrameInspector : public Widget {
        YQ_TACHYON_DECLARE(FrameInspector, Widget)
    public:
        FrameInspector();
        ~FrameInspector();
        
        virtual void    imgui_(ViContext&);
        
        static void init_info();
    private:
        TextLabel*  m_la1;
    };
}
