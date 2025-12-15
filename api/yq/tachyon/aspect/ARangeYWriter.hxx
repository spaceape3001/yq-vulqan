////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/ARangeY.hpp>
#include <yq/tachyon/command/range/SetRangeYCommand.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void ARangeʸ::init_meta(TachyonMeta::Writer<C>&w)
    {
        w.template interface<IRangeʸ>();
        w.property(UNSAFE, "y_range", &ARangeʸ::m_yRange).tag(kTag_Save);

        w.slot(UNSAFE, &ARangeʸ::on_set_y_range);
    }
}
