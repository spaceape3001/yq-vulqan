////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <yq/tachyon/interface/ITopology.hpp>
#include <yq/tachyon/api/Tachyon.hpp>

namespace yq::tachyon {
    class SetTopologyCommand;
    
    class ATopology : public ITopology, public virtual Tachyon::Helper {
    public:
        
        Topology  topology() const override { return m_topology; }

        virtual bool    topology(disabled_k) const override { return false; }
        virtual bool    topology(settable_k) const override { return false; }
        
        // override to accept/reject
        virtual void    topology(set_k, Topology);
        
    protected:

        static constexpr const Topology     kDefTopology    = Topology::TriangleList;

        Topology    m_topology  = kDefTopology;

        template <typename C>
        static void init_meta(TachyonMeta::Writer<C>&);
        
        ATopology();
        virtual ~ATopology();
        
    private:
        void    on_set_topology(const SetTopologyCommand&);

    };
}
