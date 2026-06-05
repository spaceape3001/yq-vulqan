////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMinSize3CMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMinSize³CMCommand)

namespace yq::tachyon {
    SetMinSize³CMCommand::SetMinSize³CMCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMinSize³CMCommand::SetMinSize³CMCommand(const Header& h, const Size3CM& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetMinSize³CMCommand::SetMinSize³CMCommand(const SetMinSize³CMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetMinSize³CMCommand::~SetMinSize³CMCommand()
    {
    }

    PostCPtr    SetMinSize³CMCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMinSize³CMCommand(*this, h);
    }
    
    void SetMinSize³CMCommand::init_meta()
    {
        auto w = writer<SetMinSize³CMCommand>();
        w.description("SetMin Size CMCommand in 3D");
        w.property("x", &SetMinSize³CMCommand::x).tag(kTag_Log);
        w.property("y", &SetMinSize³CMCommand::y).tag(kTag_Log);
        w.property("z", &SetMinSize³CMCommand::z).tag(kTag_Log);
        w.property("size", &SetMinSize³CMCommand::m_size).tag(kTag_Save);
    }
}
