////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIElementWriter.hpp>
#include <yq/tachyon/ui/UIImage.hpp>

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
