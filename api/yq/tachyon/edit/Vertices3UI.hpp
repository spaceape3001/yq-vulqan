////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    class Vertices³UI : public UIEditor {
        YQ_OBJECT_DECLARE(Vertices³UI, UIEditor)
    public:
        Vertices³UI(UIFlags flags={});
        Vertices³UI(const Vertices³UI&);
        
        virtual Vertices³UI* clone() const;
        
        void    vertices();
        
        static void init_meta();
    };
}
