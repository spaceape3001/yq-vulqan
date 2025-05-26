////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIElementsWriter.hpp>

namespace yq::tachyon {
    class UIGroup;
    
    class UIGroupWriter : public UIElementsWriter {
    public:
        UIGroupWriter();
        UIGroupWriter(UIGroup*);
        UIGroupWriter(const UIGroupWriter&);
        ~UIGroupWriter();
        
        UIGroup*  element();
    };
}
