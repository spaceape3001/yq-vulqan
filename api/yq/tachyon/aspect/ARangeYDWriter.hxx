////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/ARangeYD.hpp>
#include <yq/tachyon/command/range/SetRangeYDCommand.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void ARangeʸD::init_meta(TachyonMeta::Writer<C>&w)
    {
        w.template interface<IRangeʸD>();
        w.property(UNSAFE, "y_range", &ARangeʸD::m_yRange).tag(kTag_Save);

        w.slot(UNSAFE, &ARangeʸD::on_set_y_range);
    }
}
