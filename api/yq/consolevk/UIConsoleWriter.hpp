////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIElementWriter.hpp>
#include <yq/typedef/size2.hpp>

namespace yq::tachyon {
    class UIConsole;
    
    class UIConsoleWriter : public UIElementWriter {
    public:
        UIConsoleWriter();
        UIConsoleWriter(UIConsole*);
        UIConsoleWriter(const UIConsoleWriter&);
        ~UIConsoleWriter();
        
        UIConsole*  element();

        UIConsoleWriter&    size(const Size2F&);

        /////////////////////////////////////////////
        // Element Creation Helpers
        /////////////////////////////////////////////

        // We'll have some tool button things....
    };
}
