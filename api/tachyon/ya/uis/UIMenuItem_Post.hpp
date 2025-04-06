////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/uis/UIMenuItem.hpp>
#include <yt/msg/Post.hpp>

namespace yq::tachyon {
    template <SomePost P>
    class UIMenuItem_Post : public UIMenuItem {
    public:
    
        UIMenuItem_Post(std::string_view name, std::string_view scut={}) :
            UIMenuItem(name, scut)
        {
        }
        
        UIMenuItem_Post(const UIMenuItem_Post&cp) : UIMenuItem(cp)
        {
        }
        
        ~UIMenuItem_Post()
        {
        }
       
        UIMenuItem_Post*     clone() const
        {
            return new UIMenuItem_Post(*this);
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
