////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetScale1DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetScale¹DCommand)

namespace yq::tachyon {
    SetScale¹DCommand::SetScale¹DCommand(const Header& h, const Vector1D& v) : 
        ScaleCommand(h), m_scale(v)
    {
    }
    
    SetScale¹DCommand::SetScale¹DCommand(const SetScale¹DCommand& cp, const Header& h) : 
        ScaleCommand(cp, h), m_scale(cp.m_scale)
    {
    }

    SetScale¹DCommand::~SetScale¹DCommand()
    {
    }
    
    PostCPtr    SetScale¹DCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetScale¹DCommand(*this, h);
    }

    void SetScale¹DCommand::init_meta()
    {
        auto w = writer<SetScale¹DCommand>();
        w.description("Set Scale Command");
        w.property("x", &SetScale¹DCommand::x);
    }
}
