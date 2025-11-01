////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIElementsWriter.hpp>

namespace yq::tachyon {
    class UIHLine;
    
    class UIHLineWriter : public UIElementsWriter {
    public:
        UIHLineWriter();
        UIHLineWriter(UIHLine*);
        UIHLineWriter(const UIHLineWriter&);
        ~UIHLineWriter();
        
        UIHLine*  element();
    };
}
