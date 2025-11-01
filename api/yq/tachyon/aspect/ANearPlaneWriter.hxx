////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/ANearPlane.hpp>
#include <yq/tachyon/command/camera/SetNearPlaneCommand.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void ANearPlane::init_meta(TachyonMeta::Writer<C>&w)
    {
        w.template interface<ANearPlane>();
        w.property(UNSAFE, "near", &ANearPlane::m_near).def_value(kDefNearPlane).tag(kTag_Save);
        w.slot(UNSAFE, &ANearPlane::on_set_near_plane);
    }
}
