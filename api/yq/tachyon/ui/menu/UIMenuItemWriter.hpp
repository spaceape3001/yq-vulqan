////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/menu/UIMenuItem.hpp>
#include <yq/tachyon/ui/UIElementWriter.hpp>

namespace yq::tachyon {
    class UIMenuItemWriter : public UIElementWriter {
    public:
        using Writer = UIMenuItemWriter;

        UIMenuItemWriter();
        UIMenuItemWriter(UIMenuItem*);
        UIMenuItemWriter(const UIMenuItemWriter&);
        ~UIMenuItemWriter();
        
        UIMenuItem*  element();
    };
}
