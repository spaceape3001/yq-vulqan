////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetSize3DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetSize³DCommand)

namespace yq::tachyon {
    SetSize³DCommand::SetSize³DCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetSize³DCommand::SetSize³DCommand(const Header& h, const Size3D& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetSize³DCommand::SetSize³DCommand(const SetSize³DCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetSize³DCommand::~SetSize³DCommand()
    {
    }

    PostCPtr    SetSize³DCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetSize³DCommand(*this, h);
    }
    
    void SetSize³DCommand::init_meta()
    {
        auto w = writer<SetSize³DCommand>();
        w.description("Set Size DCommand in 3D");
        w.property("x", &SetSize³DCommand::x).tag(kTag_Log);
        w.property("y", &SetSize³DCommand::y).tag(kTag_Log);
        w.property("z", &SetSize³DCommand::z).tag(kTag_Log);
        w.property("size", &SetSize³DCommand::m_size).tag(kTag_Save);
    }
}
