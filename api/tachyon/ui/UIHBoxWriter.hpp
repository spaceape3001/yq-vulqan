////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UILayoutWriter.hpp>

namespace yq::tachyon {
    class UIHBox;
    class UIHBoxWriter : public UILayoutWriter {
    public:
        UIHBoxWriter();
        UIHBoxWriter(UIHBox*);
        UIHBoxWriter(const UIHBoxWriter&);
        ~UIHBoxWriter();
        
        UIHBox* element();
    };
}
