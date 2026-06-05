////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetSize3CMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetSize³CMCommand)

namespace yq::tachyon {
    SetSize³CMCommand::SetSize³CMCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetSize³CMCommand::SetSize³CMCommand(const Header& h, const Size3CM& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetSize³CMCommand::SetSize³CMCommand(const SetSize³CMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetSize³CMCommand::~SetSize³CMCommand()
    {
    }

    PostCPtr    SetSize³CMCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetSize³CMCommand(*this, h);
    }
    
    void SetSize³CMCommand::init_meta()
    {
        auto w = writer<SetSize³CMCommand>();
        w.description("Set Size CMCommand in 3D");
        w.property("x", &SetSize³CMCommand::x).tag(kTag_Log);
        w.property("y", &SetSize³CMCommand::y).tag(kTag_Log);
        w.property("z", &SetSize³CMCommand::z).tag(kTag_Log);
        w.property("size", &SetSize³CMCommand::m_size).tag(kTag_Save);
    }
}
