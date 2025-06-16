////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/aspect/AFieldOfView.hpp>
#include <tachyon/command/camera/SetFOVCommand.hpp>
#include <tachyon/api/TachyonInfoWriter.hpp>
#include <tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void AFieldOfView::init_info(TachyonInfo::Writer<C>&w)
    {
        w.template interface<AFieldOfView>();
        w.property(UNSAFE, "fov", &AFieldOfView::m_fov).def_value(kDefFieldOfView).tag(kTag_Save);
        w.slot(UNSAFE, &AFieldOfView::on_set_fov);
    }
}
