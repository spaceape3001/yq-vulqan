////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/ui/UIEditor.hpp>
#include <yq/units.hpp>

namespace yq::tachyon {
    class Orientation³UI : public UIEditor {
        YQ_OBJECT_DECLARE(Orientation³UI, UIEditor)
    public:
        Orientation³UI(UIFlags flags={});
        Orientation³UI(const Orientation³UI&);
        
        virtual Orientation³UI* clone() const;
        
        void    hpr();
        void    quaternion();
        
        static void init_meta();

        unit::Degree        m_stepFast      = 10._deg;
    };
}
