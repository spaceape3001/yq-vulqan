////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class UserSpatial³UI : public UIEditor {
        YQ_OBJECT_DECLARE(UserSpatial³UI, UIEditor)
    public:
        UserSpatial³UI(UIFlags flags={});
        UserSpatial³UI(const UserSpatial³UI&);
        
        virtual UserSpatial³UI* clone() const;
        
        void    h();
        void    p();
        void    r();
        void    x();
        void    y();
        void    z();
        
        //  eventually the parent spatial?
        
        static void init_meta();
    };
}
