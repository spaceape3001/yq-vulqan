////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIElementsWriter.hpp>

namespace yq::tachyon {
    class UIForm;
    class UIFormWriter : public UIElementsWriter {
    public:
        UIFormWriter();
        UIFormWriter(UIForm*);
        UIFormWriter(const UIFormWriter&);
        ~UIFormWriter();
        
        UIForm* element();
    };
}
