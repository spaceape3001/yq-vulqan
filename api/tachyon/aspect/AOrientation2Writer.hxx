////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/aspect/AOrientation3.hpp>
#include <tachyon/command/orientation/PitchByCommand.hpp>
#include <tachyon/command/orientation/RollByCommand.hpp>
#include <tachyon/command/orientation/RotateBy2Command.hpp>
#include <tachyon/command/orientation/SetHeadingCommand.hpp>
#include <tachyon/command/orientation/SetOrientation2Command.hpp>
#include <tachyon/command/orientation/YawByCommand.hpp>
#include <tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void AOrientation²::init_info(TachyonMeta::Writer<C>& w)
    {
        w.template interface<IOrientation²>();
        w.property(UNSAFE, "orientation", &AOrientation²::m_orientation).tag(kTag_Save);
        
        w.slot(UNSAFE, &AOrientation²::on_rotate_by);
        w.slot(UNSAFE, &AOrientation²::on_set_heading);
        w.slot(UNSAFE, &AOrientation²::on_set_orientation²);
        w.slot(UNSAFE, &AOrientation²::on_yaw_by);
    }
}
