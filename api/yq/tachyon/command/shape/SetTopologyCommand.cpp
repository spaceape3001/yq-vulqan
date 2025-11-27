////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetTopologyCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetTopologyCommand)

namespace yq::tachyon {

    SetTopologyCommand::SetTopologyCommand(const Header&h, Topology dm) : ShapeCommand(h), m_topology(dm)
    {
    }

    SetTopologyCommand::SetTopologyCommand(const SetTopologyCommand& cp, const Header& h) : 
        ShapeCommand(cp, h), m_topology(cp.m_topology)
    {
    }
    
    SetTopologyCommand::~SetTopologyCommand()
    {
    }

    PostCPtr    SetTopologyCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetTopologyCommand(*this, h);
    }
    
    void        SetTopologyCommand::set_topology(Topology v)
    {
        m_topology  = v;
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void SetTopologyCommand::init_meta()
    {
        auto w = writer<SetTopologyCommand>();
        w.description("Set Topology Command");
        w.property("topology", &SetTopologyCommand::m_topology).tag({kTag_Log, kTag_Save});
    }
}
