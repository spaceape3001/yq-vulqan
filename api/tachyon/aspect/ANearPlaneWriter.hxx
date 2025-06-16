////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/aspect/ANearPlane.hpp>
#include <tachyon/command/camera/SetNearPlaneCommand.hpp>
#include <tachyon/api/TachyonInfoWriter.hpp>
#include <tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void ANearPlane::init_info(TachyonInfo::Writer<C>&w)
    {
        w.template interface<ANearPlane>();
        w.property(UNSAFE, "near", &ANearPlane::m_near).def_value(kDefNearPlane).tag(kTag_Save);
        w.slot(UNSAFE, &ANearPlane::on_set_near_plane);
    }
}
