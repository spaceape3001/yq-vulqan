////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/aspect/AOrientation3.hpp>
#include <tachyon/command/orientation/PitchBy.hpp>
#include <tachyon/command/orientation/RollBy.hpp>
#include <tachyon/command/orientation/RotateBy3.hpp>
#include <tachyon/command/orientation/SetHeading.hpp>
#include <tachyon/command/orientation/SetOrientation3.hpp>
#include <tachyon/command/orientation/SetPitch.hpp>
#include <tachyon/command/orientation/SetRoll.hpp>
#include <tachyon/command/orientation/YawBy.hpp>
#include <tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void AOrientation³::init_info(TachyonInfo::Writer<C>& w)
    {
        w.template interface<IOrientation³>();
        w.property(UNSAFE, "orientation", &AOrientation³::m_orientation).tag(kTag_Save);
        
        w.slot(UNSAFE, &AOrientation³::on_pitch_by);
        w.slot(UNSAFE, &AOrientation³::on_roll_by);
        w.slot(UNSAFE, &AOrientation³::on_rotate_by);
        w.slot(UNSAFE, &AOrientation³::on_set_heading);
        w.slot(UNSAFE, &AOrientation³::on_set_orientation³);
        w.slot(UNSAFE, &AOrientation³::on_set_pitch);
        w.slot(UNSAFE, &AOrientation³::on_set_roll);
        w.slot(UNSAFE, &AOrientation³::on_yaw_by);
    }
}
