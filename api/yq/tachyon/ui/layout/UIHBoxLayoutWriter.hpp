////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UILayoutWriter.hpp>

namespace yq::tachyon {
    class UIHBoxLayout;
    class UIHBoxLayoutWriter : public UILayoutWriter {
    public:
        UIHBoxLayoutWriter();
        UIHBoxLayoutWriter(UIHBoxLayout*);
        UIHBoxLayoutWriter(const UIHBoxLayoutWriter&);
        ~UIHBoxLayoutWriter();
        
        UIHBoxLayout* element();
    };
}
