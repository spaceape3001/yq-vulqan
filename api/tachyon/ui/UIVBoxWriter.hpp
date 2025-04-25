////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UILayoutWriter.hpp>

namespace yq::tachyon {
    class UIVBox;
    class UIVBoxWriter : public UILayoutWriter {
    public:
        UIVBoxWriter();
        UIVBoxWriter(UIVBox*);
        UIVBoxWriter(const UIVBoxWriter&);
        ~UIVBoxWriter();
        
        UIVBox* element();
    };
}
