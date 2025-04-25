////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIWindowWriter.hpp>

namespace yq::tachyon {
    class UIButtonBar;
    
    class UIButtonBarWriter : public UIWindowWriter {
    public:
        UIButtonBarWriter();
        UIButtonBarWriter(UIButtonBar*);
        UIButtonBarWriter(const UIButtonBarWriter&);
        ~UIButtonBarWriter();
        
        UIButtonBar*  element();

        /////////////////////////////////////////////
        // Element Creation Helpers
        /////////////////////////////////////////////

        // We'll have some tool button things....
    };
}
