////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIElementsWriter.hpp>

namespace yq::tachyon {
    class UIRightAlign;
    
    class UIRightAlignWriter : public UIElementsWriter {
    public:
        UIRightAlignWriter();
        UIRightAlignWriter(UIRightAlign*);
        UIRightAlignWriter(const UIRightAlignWriter&);
        ~UIRightAlignWriter();
        
        UIRightAlign*  element();
    };
}
