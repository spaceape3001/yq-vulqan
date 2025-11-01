////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIElementWriter.hpp>

namespace yq::tachyon {
    class UIImage;
    class UIImageWriter : public UIElementWriter {
    public:
        UIImageWriter();
        UIImageWriter(UIImage*);
        UIImageWriter(const UIImageWriter&);
        ~UIImageWriter();
        
        UIImage* element();
    };
}
