////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/RenderedCommand.hpp>
#include <yq/tachyon/pipeline/Topology.hpp>

namespace yq::tachyon {
    class SetTopologyCommand : public RenderedCommand {
        YQ_OBJECT_DECLARE(SetTopologyCommand, RenderedCommand)
    public:
        SetTopologyCommand(const Header&, Topology);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        Topology        topology() const { return m_topology; }
        void            set_topology(Topology);

    protected:
        SetTopologyCommand(const SetTopologyCommand&, const Header&);
        virtual ~SetTopologyCommand();
        
    private:
    
        Topology        m_topology;

        SetTopologyCommand(const SetTopologyCommand&) = delete;
        SetTopologyCommand(SetTopologyCommand&&) = delete;
        SetTopologyCommand& operator=(const SetTopologyCommand&) = delete;
        SetTopologyCommand& operator=(SetTopologyCommand&&) = delete;
    };
}
