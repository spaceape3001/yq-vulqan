////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/AInnerTessellation2.hpp>
#include <yq/tachyon/command/tessellation/SetInnerTessellation2Command.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void AInnerTessellation²::init_meta(TachyonMeta::Writer<C>& w)
    {
        w.template interface<IInnerTessellation²>();
        w.property(UNSAFE, "inner_tessellation", &AInnerTessellation²::m_innerTessellation).tag(kTag_Save);

        w.slot(UNSAFE, &AInnerTessellation²::on_set_inner_tessellation2);
    }
}
