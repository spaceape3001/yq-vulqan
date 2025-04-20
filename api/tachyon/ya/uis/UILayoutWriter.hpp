////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/ui/UIElementWriter.hpp>

namespace yq::tachyon {
    class UILayout;
    class UILayoutWriter : public UIElementWriter {
    public:
        UILayoutWriter();
        UILayoutWriter(UILayout*);
        UILayoutWriter(const UILayoutWriter&);
        ~UILayoutWriter();
        
        UILayout* element();
    };
}
