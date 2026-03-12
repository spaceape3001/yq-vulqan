////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMaxSize2DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMaxSize²DCommand)

namespace yq::tachyon {
    SetMaxSize²DCommand::SetMaxSize²DCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMaxSize²DCommand::SetMaxSize²DCommand(const Header& h, const Size2D& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetMaxSize²DCommand::SetMaxSize²DCommand(const SetMaxSize²DCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetMaxSize²DCommand::~SetMaxSize²DCommand()
    {
    }

    PostCPtr    SetMaxSize²DCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMaxSize²DCommand(*this, h);
    }
    
    void SetMaxSize²DCommand::init_meta()
    {
        auto w = writer<SetMaxSize²DCommand>();
        w.description("SetMax Size DCommand in 2D");
        w.property("x", &SetMaxSize²DCommand::x).tag(kTag_Log);
        w.property("y", &SetMaxSize²DCommand::y).tag(kTag_Log);
        w.property("size", &SetMaxSize²DCommand::m_size).tag(kTag_Save);
    }
}
