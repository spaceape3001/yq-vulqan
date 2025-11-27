////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Proxy.hpp>
#include <yq/tachyon/interface/ITopology.hpp>

namespace yq::tachyon {
    class PTopology : public Proxy, public ITopology {
    public:
        
        PTopology(const ITopology&);
        ~PTopology();
        virtual Topology    topology() const override;
        virtual bool        topology(disabled_k) const override;
        virtual bool        topology(settable_k) const override;
        virtual void        topology(set_k, Topology) override;

    private:
        Topology    m_topology;
    };
}
