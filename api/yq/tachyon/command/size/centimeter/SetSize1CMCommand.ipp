////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetSize1CMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetSize¹CMCommand)

namespace yq::tachyon {
    SetSize¹CMCommand::SetSize¹CMCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetSize¹CMCommand::SetSize¹CMCommand(const Header& h, const Size1CM& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetSize¹CMCommand::SetSize¹CMCommand(const SetSize¹CMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetSize¹CMCommand::~SetSize¹CMCommand()
    {
    }

    PostCPtr    SetSize¹CMCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetSize¹CMCommand(*this, h);
    }
    
    void SetSize¹CMCommand::init_meta()
    {
        auto w = writer<SetSize¹CMCommand>();
        w.description("Set Size CMCommand in 1D");
        w.property("x", &SetSize¹CMCommand::x).tag(kTag_Log);
        w.property("size", &SetSize¹CMCommand::m_size).tag(kTag_Save);
    }
}
