////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/uis/UIButton.hpp>
#include <yt/msg/Post.hpp>

namespace yq::tachyon {
    template <SomePost P>
    class UIButton_Post : public UIButton {
    public:
    
        UIButton_Post(std::string_view text, const Vector2F& size) : UIButton(text, size)
        {
        }
        
        UIButton_Post(const UIButton_Post&cp) : UIButton(cp)
        {
        }
        
        ~UIButton_Post()
        {
        }
       
        UIButton_Post*     clone() const
        {
            return new UIButton_Post(*this);
        }
 
    protected:
        virtual void        triggered() override
        {
            Widget& w = widget();
            if(&w){
                w.mail(new P(Post::Header{.source=w, .target=w}));
            }
        }
    };
}
