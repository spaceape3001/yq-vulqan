////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/AOrientation3.hpp>
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
    void AOrientation³::init_meta(TachyonMeta::Writer<C>& w)
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
