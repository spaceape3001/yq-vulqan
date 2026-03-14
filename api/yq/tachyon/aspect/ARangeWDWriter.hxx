////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/ARangeWD.hpp>
#include <yq/tachyon/command/range/SetRangeWDCommand.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void ARangeʷD::init_meta(TachyonMeta::Writer<C>&w)
    {
        w.template interface<IRangeʷD>();
        w.property(UNSAFE, "w_range", &ARangeʷD::m_wRange).tag(kTag_Save);

        w.slot(UNSAFE, &ARangeʷD::on_set_w_range);
    }
}
