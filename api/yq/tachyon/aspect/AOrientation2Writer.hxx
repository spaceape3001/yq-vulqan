////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/AOrientation3.hpp>
#include <yq/tachyon/command/orientation/PitchByCommand.hpp>
#include <yq/tachyon/command/orientation/RollByCommand.hpp>
#include <yq/tachyon/command/orientation/RotateBy2Command.hpp>
#include <yq/tachyon/command/orientation/SetHeadingCommand.hpp>
#include <yq/tachyon/command/orientation/SetOrientation2Command.hpp>
#include <yq/tachyon/command/orientation/YawByCommand.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void AOrientation²::init_meta(TachyonMeta::Writer<C>& w)
    {
        w.template interface<IOrientation²>();
        w.property(UNSAFE, "orientation", &AOrientation²::m_orientation).tag(kTag_Save);
        
        w.slot(UNSAFE, &AOrientation²::on_rotate_by);
        w.slot(UNSAFE, &AOrientation²::on_set_heading);
        w.slot(UNSAFE, &AOrientation²::on_set_orientation²);
        w.slot(UNSAFE, &AOrientation²::on_yaw_by);
    }
}
