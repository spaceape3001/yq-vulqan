////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/api/Interface.hpp>
#include <yq/tachyon/pipeline/Topology.hpp>

namespace yq::tachyon {
    class PTopology;
    class ITopology {
    public:
        YQ_INTERFACE_DECLARE(ITopology, PTopology);
    
        virtual Topology    topology() const = 0;
        virtual bool        topology(disabled_k) const { return false; }
        virtual bool        topology(settable_k) const { return false; }
        virtual void        topology(set_k, Topology) {}
        static void init_meta();
    };
}
