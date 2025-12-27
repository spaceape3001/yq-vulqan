////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/ARenderMode.hpp>
#include <yq/tachyon/command/widget/SetRenderModeCommand.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void ARenderMode::init_meta(TachyonMeta::Writer<C>&w)
    {
        w.template interface<ARenderMode>();
        w.property(UNSAFE, "render_mode", &ARenderMode::m_renderMode).
            def_value(kDefRenderMode).tag(kTag_Save);
        w.slot(UNSAFE, &ARenderMode::on_set_render_mode);
    }
}
