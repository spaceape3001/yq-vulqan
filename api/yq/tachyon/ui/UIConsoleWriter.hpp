////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIElementWriter.hpp>

namespace yq::tachyon {
    class UIConsole;
    
    class UIConsoleWriter : public UIElementWriter {
    public:
        UIConsoleWriter();
        UIConsoleWriter(UIConsole*);
        UIConsoleWriter(const UIConsoleWriter&);
        ~UIConsoleWriter();
        
        UIConsole*  element();

        /////////////////////////////////////////////
        // Element Creation Helpers
        /////////////////////////////////////////////

        // We'll have some tool button things....
    };
}
