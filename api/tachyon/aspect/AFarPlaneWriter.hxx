////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/aspect/AFarPlane.hpp>
#include <tachyon/command/camera/SetFarPlaneCommand.hpp>
#include <tachyon/api/TachyonInfoWriter.hpp>
#include <tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void AFarPlane::init_info(TachyonInfo::Writer<C>&w)
    {
        w.template interface<AFarPlane>();
        w.property(UNSAFE, "far", &AFarPlane::m_far).def_value(kDefFarPlane).tag(kTag_Save);
        w.slot(UNSAFE, &AFarPlane::on_set_far_plane);
    }
}
