////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/menu/UIMenu.hpp>
#include <yq/tachyon/ui/UIElementsWriter.hpp>

namespace yq::tachyon {
    //class UIMenu;
    class UICheckBoxWriter;
    class UIMenuItemWriter;
    
    class UIMenuWriter : public UIElementsWriter {
    public:
        UIMenuWriter();
        UIMenuWriter(UIMenu*);
        UIMenuWriter(const UIMenuWriter&);
        ~UIMenuWriter();
        
        UIMenu*  element();

    };
}
