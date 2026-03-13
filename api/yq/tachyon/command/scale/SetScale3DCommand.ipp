////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetScale3DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetScale³DCommand)

namespace yq::tachyon {
    SetScale³DCommand::SetScale³DCommand(const Header& h) : 
        ScaleCommand(h)
    {
    }

    SetScale³DCommand::SetScale³DCommand(const Header& h, const Vector3D& v) : 
        ScaleCommand(h), m_scale(v)
    {
    }

    SetScale³DCommand::SetScale³DCommand(const SetScale³DCommand& cp, const Header& h) : 
        ScaleCommand(cp, h), m_scale(cp.m_scale)
    {
    }
    
    SetScale³DCommand::~SetScale³DCommand()
    {
    }

    PostCPtr    SetScale³DCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetScale³DCommand(*this, h);
    }
    
    void SetScale³DCommand::init_meta()
    {
        auto w = writer<SetScale³DCommand>();
        w.description("Set Scale Command");
        w.property("x", &SetScale³DCommand::x).tag(kTag_Log);
        w.property("y", &SetScale³DCommand::y).tag(kTag_Log);
        w.property("z", &SetScale³DCommand::z).tag(kTag_Log);
        w.property("scale", &SetScale³DCommand::m_scale).tag(kTag_Save);
    }
}
