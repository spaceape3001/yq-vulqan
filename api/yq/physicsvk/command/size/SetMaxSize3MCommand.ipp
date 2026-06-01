////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMaxSize3MCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMaxSize³MCommand)

namespace yq::tachyon {
    SetMaxSize³MCommand::SetMaxSize³MCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMaxSize³MCommand::SetMaxSize³MCommand(const Header& h, const Size3M& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetMaxSize³MCommand::SetMaxSize³MCommand(const SetMaxSize³MCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetMaxSize³MCommand::~SetMaxSize³MCommand()
    {
    }

    PostCPtr    SetMaxSize³MCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMaxSize³MCommand(*this, h);
    }
    
    void SetMaxSize³MCommand::init_meta()
    {
        auto w = writer<SetMaxSize³MCommand>();
        w.description("SetMax Size MCommand in 3D");
        w.property("x", &SetMaxSize³MCommand::x).tag(kTag_Log);
        w.property("y", &SetMaxSize³MCommand::y).tag(kTag_Log);
        w.property("z", &SetMaxSize³MCommand::z).tag(kTag_Log);
        w.property("size", &SetMaxSize³MCommand::m_size).tag(kTag_Save);
    }
}
