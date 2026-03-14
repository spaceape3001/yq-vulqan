////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/AOrientation3D.hpp>
#include <yq/tachyon/command/orientation/PitchByCommand.hpp>
#include <yq/tachyon/command/orientation/RollByCommand.hpp>
#include <yq/tachyon/command/orientation/RotateBy3Command.hpp>
#include <yq/tachyon/command/orientation/SetHeadingCommand.hpp>
#include <yq/tachyon/command/orientation/SetOrientation3Command.hpp>
#include <yq/tachyon/command/orientation/SetPitchCommand.hpp>
#include <yq/tachyon/command/orientation/SetRollCommand.hpp>
#include <yq/tachyon/command/orientation/YawByCommand.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void AOrientation³D::init_meta(TachyonMeta::Writer<C>& w)
    {
        w.template interface<IOrientation³D>();
        w.property(UNSAFE, "orientation", &AOrientation³D::m_orientation).tag(kTag_Save);
        
        w.slot(UNSAFE, &AOrientation³D::on_pitch_by);
        w.slot(UNSAFE, &AOrientation³D::on_roll_by);
        w.slot(UNSAFE, &AOrientation³D::on_rotate_by);
        w.slot(UNSAFE, &AOrientation³D::on_set_heading);
        w.slot(UNSAFE, &AOrientation³D::on_set_orientation³);
        w.slot(UNSAFE, &AOrientation³D::on_set_pitch);
        w.slot(UNSAFE, &AOrientation³D::on_set_roll);
        w.slot(UNSAFE, &AOrientation³D::on_yaw_by);
    }
}
