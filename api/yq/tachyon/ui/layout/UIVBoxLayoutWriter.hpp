////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UILayoutWriter.hpp>
#include <yq/tachyon/ui/layout/UIVBoxLayout.hpp>

namespace yq::tachyon {
    class UIVBoxLayout;
    class UIVBoxLayoutWriter : public UILayoutWriter {
    public:
        UIVBoxLayoutWriter();
        UIVBoxLayoutWriter(UIVBoxLayout*);
        UIVBoxLayoutWriter(const UIVBoxLayoutWriter&);
        ~UIVBoxLayoutWriter();
        
        UIVBoxLayout* element();
    };
}
