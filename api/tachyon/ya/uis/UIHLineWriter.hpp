////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/uis/UIElementsWriter.hpp>

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
