////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMaxSize3CMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMaxSize³CMCommand)

namespace yq::tachyon {
    SetMaxSize³CMCommand::SetMaxSize³CMCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMaxSize³CMCommand::SetMaxSize³CMCommand(const Header& h, const Size3CM& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetMaxSize³CMCommand::SetMaxSize³CMCommand(const SetMaxSize³CMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetMaxSize³CMCommand::~SetMaxSize³CMCommand()
    {
    }

    PostCPtr    SetMaxSize³CMCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMaxSize³CMCommand(*this, h);
    }
    
    void SetMaxSize³CMCommand::init_meta()
    {
        auto w = writer<SetMaxSize³CMCommand>();
        w.description("SetMax Size CMCommand in 3D");
        w.property("x", &SetMaxSize³CMCommand::x).tag(kTag_Log);
        w.property("y", &SetMaxSize³CMCommand::y).tag(kTag_Log);
        w.property("z", &SetMaxSize³CMCommand::z).tag(kTag_Log);
        w.property("size", &SetMaxSize³CMCommand::m_size).tag(kTag_Save);
    }
}
