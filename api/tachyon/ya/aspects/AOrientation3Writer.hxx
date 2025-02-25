////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/aspects/AOrientation3.hpp>
#include <ya/commands/orientation/PitchBy.hpp>
#include <ya/commands/orientation/RollBy.hpp>
#include <ya/commands/orientation/RotateBy3.hpp>
#include <ya/commands/orientation/SetHeading.hpp>
#include <ya/commands/orientation/SetOrientation3.hpp>
#include <ya/commands/orientation/SetPitch.hpp>
#include <ya/commands/orientation/SetRoll.hpp>
#include <ya/commands/orientation/YawBy.hpp>
#include <yt/tags.hpp>

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
