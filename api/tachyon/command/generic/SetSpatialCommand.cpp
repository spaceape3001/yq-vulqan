////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetSpatialCommand.hpp"
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetSpatialCommand)

namespace yq::tachyon {

    SetSpatialCommand::SetSpatialCommand(const Header&h, TypedID k) : Command(h), m_spatial(k)
    {
    
    }
    
    SetSpatialCommand::SetSpatialCommand(const SetSpatialCommand& cp, const Header& h) : 
        Command(cp, h), m_spatial(cp.m_spatial)
    {
    }
    
    SetSpatialCommand::~SetSpatialCommand()
    {
    }

    PostCPtr    SetSpatialCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetSpatialCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void SetSpatialCommand::init_info()
    {
        auto w = writer<SetSpatialCommand>();
        w.description("SetSpatial Command");
    }
}
