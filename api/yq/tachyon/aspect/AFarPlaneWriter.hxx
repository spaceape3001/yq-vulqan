////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/AFarPlane.hpp>
#include <yq/tachyon/command/camera/SetFarPlaneCommand.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void AFarPlane::init_meta(TachyonMeta::Writer<C>&w)
    {
        w.template interface<AFarPlane>();
        w.property(UNSAFE, "far", &AFarPlane::m_far).def_value(kDefFarPlane).tag(kTag_Save);
        w.slot(UNSAFE, &AFarPlane::on_set_far_plane);
    }
}
