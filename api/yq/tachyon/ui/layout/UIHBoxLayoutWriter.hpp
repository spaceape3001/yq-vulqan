////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UILayoutWriter.hpp>
#include <yq/tachyon/ui/layout/UIHBoxLayout.hpp>

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
