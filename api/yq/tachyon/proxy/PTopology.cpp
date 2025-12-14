////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PTopology.hpp"
#include <yq/tachyon/command/rendered/SetTopologyCommand.hpp>

namespace yq::tachyon {
    PTopology::PTopology(const ITopology& i) : m_topology(i.topology())
    {
        if(i.topology(DISABLED))
            m_flags |= F::Disabled;
        if(i.topology(SETTABLE))
            m_flags |= F::Settable;
    }
    
    PTopology::~PTopology()
    {
    }

    Topology    PTopology::topology() const
    {
        return m_topology;
    }
    
    bool        PTopology::topology(disabled_k) const
    {
        return m_flags(F::Disabled);
    }
    
    bool        PTopology::topology(settable_k) const
    {
        return m_flags(F::Settable);
    }
    
    void        PTopology::topology(set_k, Topology v)
    {
        if(m_flags(F::Settable) && !m_flags(F::Disabled)){
            mail(new SetTopologyCommand({.target=object()}, v));
        }
    }
}

