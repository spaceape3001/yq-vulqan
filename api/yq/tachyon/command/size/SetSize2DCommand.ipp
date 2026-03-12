////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetSize2DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetSize²DCommand)

namespace yq::tachyon {
    SetSize²DCommand::SetSize²DCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetSize²DCommand::SetSize²DCommand(const Header& h, const Size2D& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetSize²DCommand::SetSize²DCommand(const SetSize²DCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetSize²DCommand::~SetSize²DCommand()
    {
    }

    PostCPtr    SetSize²DCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetSize²DCommand(*this, h);
    }
    
    void SetSize²DCommand::init_meta()
    {
        auto w = writer<SetSize²DCommand>();
        w.description("Set Size DCommand in 2D");
        w.property("x", &SetSize²DCommand::x).tag(kTag_Log);
        w.property("y", &SetSize²DCommand::y).tag(kTag_Log);
        w.property("size", &SetSize²DCommand::m_size).tag(kTag_Save);
    }
}
