////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UITextLabel.hpp>
#include <yq/tachyon/ui/UIElementWriter.hpp>

namespace yq::tachyon {
    class UITextLabelWriter;
    
    class UITextLabelWriter : public UIElementWriter {
    public:
        using Writer = UITextLabelWriter;

        UITextLabelWriter();
        UITextLabelWriter(UITextLabel*);
        UITextLabelWriter(const UITextLabelWriter&);
        ~UITextLabelWriter();
        
        UITextLabel*  element();
    };
}
