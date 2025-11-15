////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIElementWriter.hpp>

namespace yq::tachyon {
    class UICalc;
    class UICalcWriter : public UIElementWriter {
    public:
        UICalcWriter();
        UICalcWriter(UICalc*);
        UICalcWriter(const UICalcWriter&);
        ~UICalcWriter();
        
        UICalc* element();
    };
}
