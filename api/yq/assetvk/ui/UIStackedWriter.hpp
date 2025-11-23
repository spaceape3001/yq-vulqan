////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/assetvk/ui/UIStacked.hpp>
#include <yq/tachyon/ui/UIElementsWriter.hpp>

namespace yq::tachyon {
    class UIStackedWriter : public UIElementsWriter {
    public:
        UIStackedWriter();
        UIStackedWriter(UIStacked*);
        UIStackedWriter(const UIStackedWriter&);
        ~UIStackedWriter();
        
        UIStacked*  element();
        
        UIStackedWriter&    select(size_t);
        UIStackedWriter&    dummy(const Size2F&);
    };
}
