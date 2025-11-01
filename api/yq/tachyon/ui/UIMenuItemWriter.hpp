////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIElementWriter.hpp>

namespace yq::tachyon {
    class UIMenuItem;
    
    class UIMenuItemWriter;
    
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
