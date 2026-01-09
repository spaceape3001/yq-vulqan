////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/layout/UISpacer.hpp>
#include <yq/tachyon/ui/UIElementWriter.hpp>

namespace yq::tachyon {
    class UISpacerWriter : public UIElementWriter {
    public:
        UISpacerWriter();
        UISpacerWriter(UISpacer*);
        UISpacerWriter(const UISpacerWriter&);
        ~UISpacerWriter();
        
        UISpacer* element();
        
    };
}
