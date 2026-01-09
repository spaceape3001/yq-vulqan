////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/input/UIButton.hpp>
#include <yq/tachyon/ui/UIElementWriter.hpp>

namespace yq::tachyon {
    class UIButton;
    class UIButtonWriter : public UIElementWriter {
    public:
        UIButtonWriter();
        UIButtonWriter(UIButton*);
        UIButtonWriter(const UIButtonWriter&);
        ~UIButtonWriter();
        
        UIButton* element();
    };
}
