////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class TextureUI : public UIEditor {
        YQ_OBJECT_DECLARE(TextureUI, UIEditor)
    public:
        TextureUI(UIFlags flags={});
        TextureUI(const TextureUI&);
        
        virtual TextureUI* clone() const;
        
        void    texture();
        
        static void init_meta();
    };
}
