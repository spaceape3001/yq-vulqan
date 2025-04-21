////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/uis/UIElementsWriter.hpp>

namespace yq::tachyon {
    class UILayout;
    class UIWindowWriter;
    
    class UILayoutWriter : public UIElementsWriter {
    public:
        UILayoutWriter();
        UILayoutWriter(UILayout*);
        UILayoutWriter(const UILayoutWriter&);
        ~UILayoutWriter();
        
        UILayout* element();

        UIWindowWriter      window(std::string_view kName={});
    };
}
