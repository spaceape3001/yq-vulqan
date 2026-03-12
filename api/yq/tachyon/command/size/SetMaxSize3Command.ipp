////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMaxSize3DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMaxSize³DCommand)

namespace yq::tachyon {
    SetMaxSize³DCommand::SetMaxSize³DCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMaxSize³DCommand::SetMaxSize³DCommand(const Header& h, const Size3D& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetMaxSize³DCommand::SetMaxSize³DCommand(const SetMaxSize³DCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetMaxSize³DCommand::~SetMaxSize³DCommand()
    {
    }

    PostCPtr    SetMaxSize³DCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMaxSize³DCommand(*this, h);
    }
    
    void SetMaxSize³DCommand::init_meta()
    {
        auto w = writer<SetMaxSize³DCommand>();
        w.description("SetMax Size DCommand in 3D");
        w.property("x", &SetMaxSize³DCommand::x).tag(kTag_Log);
        w.property("y", &SetMaxSize³DCommand::y).tag(kTag_Log);
        w.property("z", &SetMaxSize³DCommand::z).tag(kTag_Log);
        w.property("size", &SetMaxSize³DCommand::m_size).tag(kTag_Save);
    }
}
