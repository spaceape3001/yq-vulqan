////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/menu/UIMenuBar.hpp>
#include <yq/tachyon/ui/UIElementsWriter.hpp>

namespace yq::tachyon {
    class UIMenuBar;
    class UIMenuWriter;
    class UIMenuItemWriter;
    
    class UIMenuBarWriter : public UIElementsWriter {
    public:
        UIMenuBarWriter();
        UIMenuBarWriter(UIMenuBar*);
        UIMenuBarWriter(const UIMenuBarWriter&);
        ~UIMenuBarWriter();
        
        UIMenuBar*  element();

        /////////////////////////////////////////////
        // Element Creation Helpers
        /////////////////////////////////////////////


    };
}
