////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/ui/UIElement.hpp>
#include <yt/typedef/texture.hpp>

namespace yq::tachyon {
    class UIImageWriter;

    //! Anything image related derives from this
    class UIImage : public UIElement {
        YQ_OBJECT_DECLARE(UIImage, UIElement)
    public:
    
        using Writer = UIImageWriter;
    
        UIImage(UIFlags flags={});
        UIImage(const UIImage&);
        ~UIImage();
        
        UIImage* clone() const;
        
        static void init_info();
        
    protected:
        
        //  helpers here....
        
        static TextureCPtr      texture(std::string_view);

    };
}
