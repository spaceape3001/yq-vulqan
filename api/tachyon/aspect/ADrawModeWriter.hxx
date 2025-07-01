////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/aspect/ADrawMode.hpp>
#include <tachyon/command/shape/SetDrawModeCommand.hpp>
#include <tachyon/api/TachyonMetaWriter.hpp>
#include <tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void ADrawMode::init_info(TachyonMeta::Writer<C>&w)
    {
        w.template interface<ADrawMode>();
        w.property(UNSAFE, "draw_mode", &ADrawMode::m_drawMode).
            def_value(DrawMode::Auto).tag(kTag_Save);
        w.slot(UNSAFE, &ADrawMode::on_set_draw_mode);
    }
}
