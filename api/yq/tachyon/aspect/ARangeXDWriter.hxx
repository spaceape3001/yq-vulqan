////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/ARangeXD.hpp>
#include <yq/tachyon/command/range/SetRangeXDCommand.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void ARangeˣD::init_meta(TachyonMeta::Writer<C>&w)
    {
        w.template interface<IRangeˣD>();
        w.property(UNSAFE, "x_range", &ARangeˣD::m_xRange).tag(kTag_Save);

        w.slot(UNSAFE, &ARangeˣD::on_set_x_range);
    }
}
