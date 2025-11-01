////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/AFieldOfView.hpp>
#include <yq/tachyon/command/camera/SetFOVCommand.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void AFieldOfView::init_meta(TachyonMeta::Writer<C>&w)
    {
        w.template interface<AFieldOfView>();
        w.property(UNSAFE, "fov", &AFieldOfView::m_fov).def_value(kDefFieldOfView).tag(kTag_Save);
        w.slot(UNSAFE, &AFieldOfView::on_set_fov);
    }
}
