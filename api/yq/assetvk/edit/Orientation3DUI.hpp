////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/ui/UIEditor.hpp>
#include <yq/units.hpp>

namespace yq::tachyon {
    class Orientation³DUI : public UIEditor {
        YQ_OBJECT_DECLARE(Orientation³DUI, UIEditor)
    public:
        Orientation³DUI(UIFlags flags={});
        Orientation³DUI(const Orientation³DUI&);
        
        virtual Orientation³DUI* clone() const;
        
        void    hpr();
        void    quaternion();
        
        static void init_meta();

        unit::Degree        m_stepFast      = 10._deg;
    };
}
