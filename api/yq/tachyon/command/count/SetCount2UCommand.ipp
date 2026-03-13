////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetCount2UCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetCount²UCommand)

namespace yq::tachyon {
    SetCount²UCommand::SetCount²UCommand(const Header& h) : 
        CountCommand(h)
    {
    }

    SetCount²UCommand::SetCount²UCommand(const Header& h, const Vector2U& v) : 
        CountCommand(h), m_count(v)
    {
    }

    SetCount²UCommand::SetCount²UCommand(const SetCount²UCommand& cp, const Header& h) : 
        CountCommand(cp, h), m_count(cp.m_count)
    {
    }
    
    SetCount²UCommand::~SetCount²UCommand()
    {
    }

    PostCPtr    SetCount²UCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetCount²UCommand(*this, h);
    }
    
    void SetCount²UCommand::init_meta()
    {
        auto w = writer<SetCount²UCommand>();
        w.description("Set Count Command in 2D");
        w.property("x", &SetCount²UCommand::x).tag(kTag_Log);
        w.property("y", &SetCount²UCommand::y).tag(kTag_Log);
        w.property("count", &SetCount²UCommand::m_count).tag(kTag_Save);
    }
}
