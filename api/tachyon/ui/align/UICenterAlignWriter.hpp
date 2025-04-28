////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIElementsWriter.hpp>

namespace yq::tachyon {
    class UICenterAlign;
    
    class UICenterAlignWriter : public UIElementsWriter {
    public:
        UICenterAlignWriter();
        UICenterAlignWriter(UICenterAlign*);
        UICenterAlignWriter(const UICenterAlignWriter&);
        ~UICenterAlignWriter();
        
        UICenterAlign*  element();
    };
}
