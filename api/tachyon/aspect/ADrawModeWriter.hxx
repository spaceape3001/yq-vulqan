////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/aspect/ADrawMode.hpp>
#include <tachyon/command/shape/SetDrawModeCommand.hpp>
#include <tachyon/api/TachyonInfoWriter.hpp>
#include <tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void ADrawMode::init_info(TachyonInfo::Writer<C>&w)
    {
        w.template interface<ADrawMode>();
        w.property(UNSAFE, "color", &ADrawMode::m_drawMode).
            def_value({0.,0.,0.,-1.}).tag(kTag_Save);
        w.slot(UNSAFE, &ADrawMode::on_set_draw_mode);
    }
}
