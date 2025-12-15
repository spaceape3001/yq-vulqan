////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/AOuterTessellation4.hpp>
#include <yq/tachyon/command/tessellation/SetOuterTessellation4Command.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void AOuterTessellation⁴::init_meta(TachyonMeta::Writer<C>& w)
    {
        w.template interface<IOuterTessellation⁴>();
        w.property(UNSAFE, "outer_tessellation", &AOuterTessellation⁴::m_outerTessellation).tag(kTag_Save);

        w.slot(UNSAFE, &AOuterTessellation⁴::on_set_outer_tessellation4);
    }
}
