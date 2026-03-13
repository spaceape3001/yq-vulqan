////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetCount2Command.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetCount²Command)

namespace yq::tachyon {
    SetCount²Command::SetCount²Command(const Header& h) : 
        CountCommand(h)
    {
    }

    SetCount²Command::SetCount²Command(const Header& h, const Vector2U& v) : 
        CountCommand(h), m_count(v)
    {
    }

    SetCount²Command::SetCount²Command(const SetCount²Command& cp, const Header& h) : 
        CountCommand(cp, h), m_count(cp.m_count)
    {
    }
    
    SetCount²Command::~SetCount²Command()
    {
    }

    PostCPtr    SetCount²Command::clone(rebind_k, const Header&h) const 
    {
        return new SetCount²Command(*this, h);
    }
    
    void SetCount²Command::init_meta()
    {
        auto w = writer<SetCount²Command>();
        w.description("Set Count Command in 2D");
        w.property("x", &SetCount²Command::x).tag(kTag_Log);
        w.property("y", &SetCount²Command::y).tag(kTag_Log);
        w.property("count", &SetCount²Command::m_count).tag(kTag_Save);
    }
}
