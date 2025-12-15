////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/ARangeX.hpp>
#include <yq/tachyon/command/range/SetRangeXCommand.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void ARangeˣ::init_meta(TachyonMeta::Writer<C>&w)
    {
        w.template interface<IRangeˣ>();
        w.property(UNSAFE, "x_range", &ARangeˣ::m_xRange).tag(kTag_Save);

        w.slot(UNSAFE, &ARangeˣ::on_set_x_range);
    }
}
