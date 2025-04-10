////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/ui/UIElementWriter.hpp>

namespace yq::tachyon {
    class UIButton;
    class UIButtonWriter : public UIElementWriter {
    public:
        UIButtonWriter();
        UIButtonWriter(UIButton*);
        UIButtonWriter(const UIButtonWriter&);
        ~UIButtonWriter();
        
        UIButton* element();
        
    protected:
    };
}
