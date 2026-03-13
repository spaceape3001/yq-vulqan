////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetCount1UCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetCount¹UCommand)

namespace yq::tachyon {
    SetCount¹UCommand::SetCount¹UCommand(const Header& h) : 
        CountCommand(h)
    {
    }

    SetCount¹UCommand::SetCount¹UCommand(const Header& h, const Vector1U& v) : 
        CountCommand(h), m_count(v)
    {
    }

    SetCount¹UCommand::SetCount¹UCommand(const SetCount¹UCommand& cp, const Header& h) : 
        CountCommand(cp, h), m_count(cp.m_count)
    {
    }
    
    SetCount¹UCommand::~SetCount¹UCommand()
    {
    }

    PostCPtr    SetCount¹UCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetCount¹UCommand(*this, h);
    }
    
    void SetCount¹UCommand::init_meta()
    {
        auto w = writer<SetCount¹UCommand>();
        w.description("Set Count Command in 1D");
        w.property("x", &SetCount¹UCommand::x).tag(kTag_Log);
        w.property("count", &SetCount¹UCommand::m_count).tag(kTag_Save);
    }
}
