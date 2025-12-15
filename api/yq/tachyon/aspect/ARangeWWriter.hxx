////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/ARangeW.hpp>
#include <yq/tachyon/command/range/SetRangeWCommand.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void ARangeʷ::init_meta(TachyonMeta::Writer<C>&w)
    {
        w.template interface<IRangeʷ>();
        w.property(UNSAFE, "w_range", &ARangeʷ::m_wRange).tag(kTag_Save);

        w.slot(UNSAFE, &ARangeʷ::on_set_w_range);
    }
}
