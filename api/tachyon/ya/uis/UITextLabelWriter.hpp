////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/ui/UIElementWriter.hpp>

namespace yq::tachyon {
    class UITextLabel;
    
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
