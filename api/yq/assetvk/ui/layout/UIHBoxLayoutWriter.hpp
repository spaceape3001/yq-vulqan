////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UILayoutWriter.hpp>
#include <yq/assetvk/ui/layout/UIHBoxLayout.hpp>

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
