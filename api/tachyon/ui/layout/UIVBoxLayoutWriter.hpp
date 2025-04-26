////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UILayoutWriter.hpp>

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
