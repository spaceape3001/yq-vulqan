////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetCount4UCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetCount⁴UCommand)

namespace yq::tachyon {
    SetCount⁴UCommand::SetCount⁴UCommand(const Header& h) : 
        CountCommand(h)
    {
    }

    SetCount⁴UCommand::SetCount⁴UCommand(const Header& h, const Vector4U& v) : 
        CountCommand(h), m_count(v)
    {
    }

    SetCount⁴UCommand::SetCount⁴UCommand(const SetCount⁴UCommand& cp, const Header& h) : 
        CountCommand(cp, h), m_count(cp.m_count)
    {
    }
    
    SetCount⁴UCommand::~SetCount⁴UCommand()
    {
    }

    PostCPtr    SetCount⁴UCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetCount⁴UCommand(*this, h);
    }
    
    void SetCount⁴UCommand::init_meta()
    {
        auto w = writer<SetCount⁴UCommand>();
        w.description("Set Count Command in 4D");
        w.property("x", &SetCount⁴UCommand::x).tag(kTag_Log);
        w.property("y", &SetCount⁴UCommand::y).tag(kTag_Log);
        w.property("z", &SetCount⁴UCommand::z).tag(kTag_Log);
        w.property("w", &SetCount⁴UCommand::w).tag(kTag_Log);
        w.property("count", &SetCount⁴UCommand::m_count).tag(kTag_Save);
    }
}
