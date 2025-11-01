////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIWindowWriter.hpp>

namespace yq::tachyon {
    class UIToolBar;
    
    class UIToolBarWriter : public UIWindowWriter {
    public:
        UIToolBarWriter();
        UIToolBarWriter(UIToolBar*);
        UIToolBarWriter(const UIToolBarWriter&);
        ~UIToolBarWriter();
        
        UIToolBar*  element();

        /////////////////////////////////////////////
        // Element Creation Helpers
        /////////////////////////////////////////////

        // We'll have some tool button things....
    };
}
