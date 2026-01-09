////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIElementsWriter.hpp>
#include <yq/tachyon/ui/align/UIRightAlign.hpp>

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
