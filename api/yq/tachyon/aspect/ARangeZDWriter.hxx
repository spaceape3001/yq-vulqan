////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/ARangeZD.hpp>
#include <yq/tachyon/command/range/SetRangeZDCommand.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void ARangeᶻD::init_meta(TachyonMeta::Writer<C>&w)
    {
        w.template interface<IRangeᶻD>();
        w.property(UNSAFE, "z_range", &ARangeᶻD::m_zRange).tag(kTag_Save);

        w.slot(UNSAFE, &ARangeᶻD::on_set_z_range);
    }
}
