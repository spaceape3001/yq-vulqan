////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/aspect/AOrientation3.hpp>
#include <tachyon/command/orientation/PitchBy.hpp>
#include <tachyon/command/orientation/RollBy.hpp>
#include <tachyon/command/orientation/RotateBy2.hpp>
#include <tachyon/command/orientation/SetHeading.hpp>
#include <tachyon/command/orientation/SetOrientation2.hpp>
#include <tachyon/command/orientation/YawBy.hpp>
#include <tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void AOrientation²::init_info(TachyonInfo::Writer<C>& w)
    {
        w.template interface<IOrientation²>();
        w.property(UNSAFE, "orientation", &AOrientation²::m_orientation).tag(kTag_Save);
        
        w.slot(UNSAFE, &AOrientation²::on_rotate_by);
        w.slot(UNSAFE, &AOrientation²::on_set_heading);
        w.slot(UNSAFE, &AOrientation²::on_set_orientation²);
        w.slot(UNSAFE, &AOrientation²::on_yaw_by);
    }
}
