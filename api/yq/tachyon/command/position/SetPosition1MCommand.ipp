////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPosition1MCommand.hpp"
#include <yq/tags.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>
#include <yq/unit/metatype.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPosition¹MCommand)

namespace yq::tachyon {
    SetPosition¹MCommand::SetPosition¹MCommand(const Header&h, const Meter1D& v) : 
        PositionCommand(h), m_position(v)
    {
    }
    
    SetPosition¹MCommand::SetPosition¹MCommand(const SetPosition¹MCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_position(cp.m_position)
    {
    }

    SetPosition¹MCommand::~SetPosition¹MCommand()
    {
    }

    PostCPtr    SetPosition¹MCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetPosition¹MCommand(*this, h);
    }
    
    void SetPosition¹MCommand::init_meta()
    {
        auto w = writer<SetPosition¹MCommand>();
        w.description("Set Position Command");
        w.property("x", &SetPosition¹MCommand::x).tag(kTag_Log);
        w.property("position", &SetPosition¹MCommand::m_position).tag(kTag_Save);
    }
}
