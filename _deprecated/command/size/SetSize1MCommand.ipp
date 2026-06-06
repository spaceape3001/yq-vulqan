////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetSize1MCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetSize¹MCommand)

namespace yq::tachyon {
    SetSize¹MCommand::SetSize¹MCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetSize¹MCommand::SetSize¹MCommand(const Header& h, const Size1M& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetSize¹MCommand::SetSize¹MCommand(const SetSize¹MCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetSize¹MCommand::~SetSize¹MCommand()
    {
    }

    PostCPtr    SetSize¹MCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetSize¹MCommand(*this, h);
    }
    
    void SetSize¹MCommand::init_meta()
    {
        auto w = writer<SetSize¹MCommand>();
        w.description("Set Size MCommand in 1D");
        w.property("x", &SetSize¹MCommand::x).tag(kTag_Log);
        w.property("size", &SetSize¹MCommand::m_size).tag(kTag_Save);
    }
}
