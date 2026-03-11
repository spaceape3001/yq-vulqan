////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetPosition1DCommand.hpp"
#include <yq/tags.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPosition¹DCommand)

namespace yq::tachyon {
    SetPosition¹DCommand::SetPosition¹DCommand(const Header&h, const Vector1D& v) : 
        PositionCommand(h), m_position(v)
    {
    }
    
    SetPosition¹DCommand::SetPosition¹DCommand(const SetPosition¹DCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_position(cp.m_position)
    {
    }

    SetPosition¹DCommand::~SetPosition¹DCommand()
    {
    }

    PostCPtr    SetPosition¹DCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetPosition¹DCommand(*this, h);
    }
    
    void SetPosition¹DCommand::init_meta()
    {
        auto w = writer<SetPosition¹DCommand>();
        w.description("Set Position Command");
        w.property("x", &SetPosition¹DCommand::x).tag(kTag_Log);
        w.property("position", &SetPosition¹DCommand::m_position).tag(kTag_Save);
    }
}
