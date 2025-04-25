////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/UIElementWriter.hpp>
#include <tachyon/typedef/accessors.hpp>

namespace yq::tachyon {
    class UICheckBox;
    class UICheckBoxWriter : public UIElementWriter {
    public:
        UICheckBoxWriter();
        UICheckBoxWriter(UICheckBox*);
        UICheckBoxWriter(const UICheckBoxWriter&);
        ~UICheckBoxWriter();
        
        UICheckBox* element();
        
        UICheckBoxWriter&   state(bool);
        //UICheckBoxWriter&   state(Tristate);
        UICheckBoxWriter&   state(BooleanAccessorUPtr&&);
        //UICheckBoxWriter&   state(TristateAccessorUPtr&&);
    };
}
