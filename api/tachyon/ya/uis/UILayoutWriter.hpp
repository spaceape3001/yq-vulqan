////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/uis/UIElementsWriter.hpp>

namespace yq::tachyon {
    class UILayout;
    class UILayoutWriter : public UIElementsWriter {
    public:
        UILayoutWriter();
        UILayoutWriter(UILayout*);
        UILayoutWriter(const UILayoutWriter&);
        ~UILayoutWriter();
        
        UILayout* element();
    };
}
