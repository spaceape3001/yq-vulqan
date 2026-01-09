////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIElementsWriter.hpp>
#include <yq/tachyon/ui/align/UIHLine.hpp>

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
