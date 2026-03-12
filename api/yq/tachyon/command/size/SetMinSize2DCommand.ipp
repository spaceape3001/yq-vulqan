////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMinSize2DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMinSize²DCommand)

namespace yq::tachyon {
    SetMinSize²DCommand::SetMinSize²DCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMinSize²DCommand::SetMinSize²DCommand(const Header& h, const Size2D& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetMinSize²DCommand::SetMinSize²DCommand(const SetMinSize²DCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetMinSize²DCommand::~SetMinSize²DCommand()
    {
    }

    PostCPtr    SetMinSize²DCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMinSize²DCommand(*this, h);
    }
    
    void SetMinSize²DCommand::init_meta()
    {
        auto w = writer<SetMinSize²DCommand>();
        w.description("SetMin Size DCommand in 2D");
        w.property("x", &SetMinSize²DCommand::x).tag(kTag_Log);
        w.property("y", &SetMinSize²DCommand::y).tag(kTag_Log);
        w.property("size", &SetMinSize²DCommand::m_size).tag(kTag_Save);
    }
}
