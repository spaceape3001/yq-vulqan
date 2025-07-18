////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/aspect/AColor.hpp>
#include <tachyon/command/color/SetColorCommand.hpp>
#include <tachyon/api/TachyonMetaWriter.hpp>
#include <tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void AColor::init_meta(TachyonMeta::Writer<C>&w)
    {
        w.template interface<AColor>();
        w.property(UNSAFE, "color", &AColor::m_color).def_value(kDefColor).tag(kTag_Save);
        w.slot(UNSAFE, &AColor::on_set_color);
    }
}
