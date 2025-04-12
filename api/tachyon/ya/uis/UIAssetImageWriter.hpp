////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/uis/UIImageWriter.hpp>

namespace yq::tachyon {
    class UIAssetImage;
    class UIAssetImageWriter : public UIImageWriter {
    public:
        UIAssetImageWriter();
        UIAssetImageWriter(UIAssetImage*);
        UIAssetImageWriter(const UIAssetImageWriter&);
        ~UIAssetImageWriter();
        
        UIAssetImage* element();
    };
}
