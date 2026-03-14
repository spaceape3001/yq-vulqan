////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/AOrientation3D.hpp>
#include <yq/tachyon/command/orientation/PitchByCommand.hpp>
#include <yq/tachyon/command/orientation/RollByCommand.hpp>
#include <yq/tachyon/command/orientation/RotateBy2Command.hpp>
#include <yq/tachyon/command/orientation/SetHeadingCommand.hpp>
#include <yq/tachyon/command/orientation/SetOrientation2Command.hpp>
#include <yq/tachyon/command/orientation/YawByCommand.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void AOrientation²D::init_meta(TachyonMeta::Writer<C>& w)
    {
        w.template interface<IOrientation²D>();
        w.property(UNSAFE, "orientation", &AOrientation²D::m_orientation).tag(kTag_Save);
        
        w.slot(UNSAFE, &AOrientation²D::on_rotate_by);
        w.slot(UNSAFE, &AOrientation²D::on_set_heading);
        w.slot(UNSAFE, &AOrientation²D::on_set_orientation²);
        w.slot(UNSAFE, &AOrientation²D::on_yaw_by);
    }
}
