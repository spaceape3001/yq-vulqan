////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetCount1Command.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetCount¹Command)

namespace yq::tachyon {
    SetCount¹Command::SetCount¹Command(const Header& h) : 
        CountCommand(h)
    {
    }

    SetCount¹Command::SetCount¹Command(const Header& h, const Vector1U& v) : 
        CountCommand(h), m_count(v)
    {
    }

    SetCount¹Command::SetCount¹Command(const SetCount¹Command& cp, const Header& h) : 
        CountCommand(cp, h), m_count(cp.m_count)
    {
    }
    
    SetCount¹Command::~SetCount¹Command()
    {
    }

    PostCPtr    SetCount¹Command::clone(rebind_k, const Header&h) const 
    {
        return new SetCount¹Command(*this, h);
    }
    
    void SetCount¹Command::init_meta()
    {
        auto w = writer<SetCount¹Command>();
        w.description("Set Count Command in 1D");
        w.property("x", &SetCount¹Command::x).tag(kTag_Log);
        w.property("count", &SetCount¹Command::m_count).tag(kTag_Save);
    }
}
