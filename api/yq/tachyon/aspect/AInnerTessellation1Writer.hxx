////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/AInnerTessellation1.hpp>
#include <yq/tachyon/command/tessellation/SetInnerTessellation1Command.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void AInnerTessellation¹::init_meta(TachyonMeta::Writer<C>& w)
    {
        w.template interface<IInnerTessellation¹>();
        w.property(UNSAFE, "inner_tessellation", &AInnerTessellation¹::m_innerTessellation).tag(kTag_Save);

        w.slot(UNSAFE, &AInnerTessellation¹::on_set_inner_tessellation1);
    }
}
