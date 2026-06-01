////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMinSize1CMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMinSize¹CMCommand)

namespace yq::tachyon {
    SetMinSize¹CMCommand::SetMinSize¹CMCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMinSize¹CMCommand::SetMinSize¹CMCommand(const Header& h, const Size1CM& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetMinSize¹CMCommand::SetMinSize¹CMCommand(const SetMinSize¹CMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetMinSize¹CMCommand::~SetMinSize¹CMCommand()
    {
    }

    PostCPtr    SetMinSize¹CMCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMinSize¹CMCommand(*this, h);
    }
    
    void SetMinSize¹CMCommand::init_meta()
    {
        auto w = writer<SetMinSize¹CMCommand>();
        w.description("SetMin Size CMCommand in 1D");
        w.property("x", &SetMinSize¹CMCommand::x).tag(kTag_Log);
        w.property("size", &SetMinSize¹CMCommand::m_size).tag(kTag_Save);
    }
}
