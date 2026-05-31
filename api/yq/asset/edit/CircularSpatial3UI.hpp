////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>

namespace yq::tachyon {
    struct CircularSpatial³Snap;
    
    class CircularSpatial³UI : public UIEditor {
        YQ_OBJECT_DECLARE(CircularSpatial³UI, UIEditor)
    public:
        CircularSpatial³UI(UIFlags flags={});
        CircularSpatial³UI(const CircularSpatial³UI&);
        
        
        const CircularSpatial³Snap*   snap() const;
        virtual CircularSpatial³UI* clone() const;
        
        //  eventually the parent spatial?
        
        void    angle();
        void    locked();
        void    period();
        void    radius();
        
        static void init_meta();
        
    };
}
