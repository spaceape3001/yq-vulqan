////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIFormWriter.hpp>

namespace yq::tachyon {
    class UIEditor;
    class UIEditorWriter : public UIFormWriter {
    public:
        UIEditorWriter();
        UIEditorWriter(UIEditor*);
        UIEditorWriter(const UIEditorWriter&);
        ~UIEditorWriter();
        
        UIEditor* element();
    };
}
