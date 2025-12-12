////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetCount4Command.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetCount⁴Command)

namespace yq::tachyon {
    SetCount⁴Command::SetCount⁴Command(const Header& h) : 
        CountCommand(h)
    {
    }

    SetCount⁴Command::SetCount⁴Command(const Header& h, const Vector4U& v) : 
        CountCommand(h), m_count(v)
    {
    }

    SetCount⁴Command::SetCount⁴Command(const SetCount⁴Command& cp, const Header& h) : 
        CountCommand(cp, h), m_count(cp.m_count)
    {
    }
    
    SetCount⁴Command::~SetCount⁴Command()
    {
    }

    PostCPtr    SetCount⁴Command::clone(rebind_k, const Header&h) const 
    {
        return new SetCount⁴Command(*this, h);
    }
    
    void SetCount⁴Command::init_meta()
    {
        auto w = writer<SetCount⁴Command>();
        w.description("Set Count Command in 4D");
        w.property("x", &SetCount⁴Command::x).tag(kTag_Log);
        w.property("y", &SetCount⁴Command::y).tag(kTag_Log);
        w.property("z", &SetCount⁴Command::z).tag(kTag_Log);
        w.property("w", &SetCount⁴Command::w).tag(kTag_Log);
        w.property("count", &SetCount⁴Command::m_count).tag(kTag_Save);
    }
}
