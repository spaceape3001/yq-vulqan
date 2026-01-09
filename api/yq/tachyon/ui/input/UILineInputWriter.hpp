////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/input/UILineInput.hpp>
#include <yq/tachyon/ui/UIElementWriter.hpp>

namespace yq::tachyon {
    class UILineInputWriter : public UIElementWriter {
    public:
        UILineInputWriter();
        UILineInputWriter(UILineInput*);
        UILineInputWriter(const UILineInputWriter&);
        ~UILineInputWriter();
        
        UILineInput* element();
        
        UILineInputWriter   capacity(uint16_t);
        UILineInputWriter   label(std::string_view);
    };
}
