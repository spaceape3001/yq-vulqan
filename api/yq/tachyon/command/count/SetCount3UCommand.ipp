////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetCount3Command.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetCount³Command)

namespace yq::tachyon {
    SetCount³Command::SetCount³Command(const Header& h) : 
        CountCommand(h)
    {
    }

    SetCount³Command::SetCount³Command(const Header& h, const Vector3U& v) : 
        CountCommand(h), m_count(v)
    {
    }

    SetCount³Command::SetCount³Command(const SetCount³Command& cp, const Header& h) : 
        CountCommand(cp, h), m_count(cp.m_count)
    {
    }
    
    SetCount³Command::~SetCount³Command()
    {
    }

    PostCPtr    SetCount³Command::clone(rebind_k, const Header&h) const 
    {
        return new SetCount³Command(*this, h);
    }
    
    void SetCount³Command::init_meta()
    {
        auto w = writer<SetCount³Command>();
        w.description("Set Count Command in 3D");
        w.property("x", &SetCount³Command::x).tag(kTag_Log);
        w.property("y", &SetCount³Command::y).tag(kTag_Log);
        w.property("z", &SetCount³Command::z).tag(kTag_Log);
        w.property("count", &SetCount³Command::m_count).tag(kTag_Save);
    }
}
