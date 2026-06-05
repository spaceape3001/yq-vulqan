////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPosition1CMCommand.hpp"
#include <yq/tags.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPosition¹CMCommand)

namespace yq::tachyon {
    SetPosition¹CMCommand::SetPosition¹CMCommand(const Header&h, const Centimeter1D& v) : 
        PositionCommand(h), m_position(v)
    {
    }
    
    SetPosition¹CMCommand::SetPosition¹CMCommand(const SetPosition¹CMCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_position(cp.m_position)
    {
    }

    SetPosition¹CMCommand::~SetPosition¹CMCommand()
    {
    }

    PostCPtr    SetPosition¹CMCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetPosition¹CMCommand(*this, h);
    }
    
    void SetPosition¹CMCommand::init_meta()
    {
        auto w = writer<SetPosition¹CMCommand>();
        w.description("Set Position Command");
        w.property("x", &SetPosition¹CMCommand::x).tag(kTag_Log);
        w.property("position", &SetPosition¹CMCommand::m_position).tag(kTag_Save);
    }
}
