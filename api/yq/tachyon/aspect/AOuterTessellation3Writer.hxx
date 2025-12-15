////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/AOuterTessellation3.hpp>
#include <yq/tachyon/command/tessellation/SetOuterTessellation3Command.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void AOuterTessellation³::init_meta(TachyonMeta::Writer<C>& w)
    {
        w.template interface<IOuterTessellation³>();
        w.property(UNSAFE, "outer_tessellation", &AOuterTessellation³::m_outerTessellation).tag(kTag_Save);

        w.slot(UNSAFE, &AOuterTessellation³::on_set_outer_tessellation3);
    }
}
