////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetScale4DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetScale⁴DCommand)

namespace yq::tachyon {
    SetScale⁴DCommand::SetScale⁴DCommand(const Header& h) : 
        ScaleCommand(h)
    {
    }

    SetScale⁴DCommand::SetScale⁴DCommand(const Header& h, const Vector4D& v) : 
        ScaleCommand(h), m_scale(v)
    {
    }

    SetScale⁴DCommand::SetScale⁴DCommand(const SetScale⁴DCommand& cp, const Header& h) : 
        ScaleCommand(cp, h), m_scale(cp.m_scale)
    {
    }
    
    SetScale⁴DCommand::~SetScale⁴DCommand()
    {
    }

    PostCPtr    SetScale⁴DCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetScale⁴DCommand(*this, h);
    }
    
    void SetScale⁴DCommand::init_meta()
    {
        auto w = writer<SetScale⁴DCommand>();
        w.description("Set Scale Command");
        w.property("w", &SetScale⁴DCommand::w).tag(kTag_Log);
        w.property("x", &SetScale⁴DCommand::x).tag(kTag_Log);
        w.property("y", &SetScale⁴DCommand::y).tag(kTag_Log);
        w.property("z", &SetScale⁴DCommand::z).tag(kTag_Log);
        w.property("scale", &SetScale⁴DCommand::m_scale).tag(kTag_Save);
    }
}
