////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIElementsWriter.hpp>

namespace yq::tachyon {
    class UIEditor;
    class UIEditorWriter : public UIElementsWriter {
    public:
        UIEditorWriter();
        UIEditorWriter(UIEditor*);
        UIEditorWriter(const UIEditorWriter&);
        ~UIEditorWriter();
        
        UIEditor* element();
    };
}
