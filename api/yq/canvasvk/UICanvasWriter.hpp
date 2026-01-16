////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/canvasvk/UICanvas.hpp>
#include <yq/tachyon/ui/UIElementWriter.hpp>
#include <yq/typedef/size2.hpp>

namespace yq::tachyon {
    class UICanvas;
    
    class UICanvasWriter : public UIElementWriter {
    public:
        UICanvasWriter();
        UICanvasWriter(UICanvas*);
        UICanvasWriter(const UICanvasWriter&);
        ~UICanvasWriter();
        
        UICanvas*  element();

        UICanvasWriter&    size(const Size2F&);

        /////////////////////////////////////////////
        // Element Creation Helpers
        /////////////////////////////////////////////

        // We'll have some tool button things....
    };
}
