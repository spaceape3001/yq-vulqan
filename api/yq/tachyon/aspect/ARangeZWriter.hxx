////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/ARangeZ.hpp>
#include <yq/tachyon/command/range/SetRangeZCommand.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void ARangeᶻ::init_meta(TachyonMeta::Writer<C>&w)
    {
        w.template interface<IRangeᶻ>();
        w.property(UNSAFE, "z_range", &ARangeᶻ::m_zRange).tag(kTag_Save);

        w.slot(UNSAFE, &ARangeᶻ::on_set_z_range);
    }
}
