////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMaxSize1MCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMaxSize¹MCommand)

namespace yq::tachyon {
    SetMaxSize¹MCommand::SetMaxSize¹MCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMaxSize¹MCommand::SetMaxSize¹MCommand(const Header& h, const Size1M& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetMaxSize¹MCommand::SetMaxSize¹MCommand(const SetMaxSize¹MCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetMaxSize¹MCommand::~SetMaxSize¹MCommand()
    {
    }

    PostCPtr    SetMaxSize¹MCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMaxSize¹MCommand(*this, h);
    }
    
    void SetMaxSize¹MCommand::init_meta()
    {
        auto w = writer<SetMaxSize¹MCommand>();
        w.description("SetMax Size MCommand in 1D");
        w.property("x", &SetMaxSize¹MCommand::x).tag(kTag_Log);
        w.property("size", &SetMaxSize¹MCommand::m_size).tag(kTag_Save);
    }
}
