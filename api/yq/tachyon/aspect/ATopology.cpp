////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ATopology.hpp"
#include "ATopologyWriter.hxx"
#include <yq/tachyon/command/shape/SetTopologyCommand.hpp>

namespace yq::tachyon {
    ATopology::ATopology() = default;
    ATopology::~ATopology() = default;

    void    ATopology::topology(set_k, Topology v)
    {
        m_topology = v;       
        mark();
    }

    void    ATopology::on_set_topology(const SetTopologyCommand&cmd)
    {
        if(cmd.target() != typed())
            return;
        topology(SET, cmd.topology());
    }
}

