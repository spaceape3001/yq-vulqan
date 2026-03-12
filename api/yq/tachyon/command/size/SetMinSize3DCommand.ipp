////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMinSize3DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMinSize³DCommand)

namespace yq::tachyon {
    SetMinSize³DCommand::SetMinSize³DCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMinSize³DCommand::SetMinSize³DCommand(const Header& h, const Size3D& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetMinSize³DCommand::SetMinSize³DCommand(const SetMinSize³DCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetMinSize³DCommand::~SetMinSize³DCommand()
    {
    }

    PostCPtr    SetMinSize³DCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMinSize³DCommand(*this, h);
    }
    
    void SetMinSize³DCommand::init_meta()
    {
        auto w = writer<SetMinSize³DCommand>();
        w.description("SetMin Size DCommand in 3D");
        w.property("x", &SetMinSize³DCommand::x).tag(kTag_Log);
        w.property("y", &SetMinSize³DCommand::y).tag(kTag_Log);
        w.property("z", &SetMinSize³DCommand::z).tag(kTag_Log);
        w.property("size", &SetMinSize³DCommand::m_size).tag(kTag_Save);
    }
}
