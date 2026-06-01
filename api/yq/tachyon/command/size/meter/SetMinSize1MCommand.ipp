////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMinSize1MCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMinSize¹MCommand)

namespace yq::tachyon {
    SetMinSize¹MCommand::SetMinSize¹MCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMinSize¹MCommand::SetMinSize¹MCommand(const Header& h, const Size1M& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetMinSize¹MCommand::SetMinSize¹MCommand(const SetMinSize¹MCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetMinSize¹MCommand::~SetMinSize¹MCommand()
    {
    }

    PostCPtr    SetMinSize¹MCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMinSize¹MCommand(*this, h);
    }
    
    void SetMinSize¹MCommand::init_meta()
    {
        auto w = writer<SetMinSize¹MCommand>();
        w.description("SetMin Size MCommand in 1D");
        w.property("x", &SetMinSize¹MCommand::x).tag(kTag_Log);
        w.property("size", &SetMinSize¹MCommand::m_size).tag(kTag_Save);
    }
}
