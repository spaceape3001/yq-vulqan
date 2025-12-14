////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/ATopology.hpp>
#include <yq/tachyon/command/rendered/SetTopologyCommand.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    template <typename C>
    void ATopology::init_meta(TachyonMeta::Writer<C>&w)
    {
        w.template interface<ATopology>();
        w.property(UNSAFE, "topology", &ATopology::m_topology).
            def_value(kDefTopology).tag(kTag_Save);
        w.slot(UNSAFE, &ATopology::on_set_topology);
    }
}
