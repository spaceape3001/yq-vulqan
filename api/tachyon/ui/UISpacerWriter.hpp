////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/ui/UIElementWriter.hpp>

namespace yq::tachyon {
    class UISpacer;
    class UISpacerWriter : public UIElementWriter {
    public:
        UISpacerWriter();
        UISpacerWriter(UISpacer*);
        UISpacerWriter(const UISpacerWriter&);
        ~UISpacerWriter();
        
        UISpacer* element();
        
    };
}
