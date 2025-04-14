////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/uis/UIElementsWriter.hpp>

namespace yq::tachyon {
    class UIMenu;
    class UIMenuItemWriter;
    
    class UIMenuWriter : public UIElementsWriter {
    public:
        UIMenuWriter();
        UIMenuWriter(UIMenu*);
        UIMenuWriter(const UIMenuWriter&);
        ~UIMenuWriter();
        
        UIMenu*  element();

        /////////////////////////////////////////////
        // Element Creation Helpers
        /////////////////////////////////////////////


        UIMenuItemWriter    menuitem(std::string_view, std::string_view scut="");

        
        UIMenuItemWriter    menuitem(dialog_k, std::string_view, std::string_view scut=""); //< TBD
        UIMenuItemWriter    menuitem(dock_k, std::string_view, std::string_view scut=""); //< TBD
        UIMenuItemWriter    menuitem(open_k, std::string_view, std::string_view scut=""); //< TBD
        UIMenuItemWriter    menuitem(widget_k, std::string_view, std::string_view scut=""); //< TBD
    };
}
