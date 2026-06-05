////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMaxSize1CMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMaxSize¹CMCommand)

namespace yq::tachyon {
    SetMaxSize¹CMCommand::SetMaxSize¹CMCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMaxSize¹CMCommand::SetMaxSize¹CMCommand(const Header& h, const Size1CM& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetMaxSize¹CMCommand::SetMaxSize¹CMCommand(const SetMaxSize¹CMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetMaxSize¹CMCommand::~SetMaxSize¹CMCommand()
    {
    }

    PostCPtr    SetMaxSize¹CMCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMaxSize¹CMCommand(*this, h);
    }
    
    void SetMaxSize¹CMCommand::init_meta()
    {
        auto w = writer<SetMaxSize¹CMCommand>();
        w.description("SetMax Size CMCommand in 1D");
        w.property("x", &SetMaxSize¹CMCommand::x).tag(kTag_Log);
        w.property("size", &SetMaxSize¹CMCommand::m_size).tag(kTag_Save);
    }
}
