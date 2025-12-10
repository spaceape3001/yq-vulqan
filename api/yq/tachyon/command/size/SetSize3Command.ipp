////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetSize3Command.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetSize³Command)

namespace yq::tachyon {
    SetSize³Command::SetSize³Command(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetSize³Command::SetSize³Command(const Header& h, const Size3D& v) : 
        SizeCommand(h), m_size(v)
    {
    }

    SetSize³Command::SetSize³Command(const SetSize³Command& cp, const Header& h) : 
        SizeCommand(cp, h), m_size(cp.m_size)
    {
    }
    
    SetSize³Command::~SetSize³Command()
    {
    }

    PostCPtr    SetSize³Command::clone(rebind_k, const Header&h) const 
    {
        return new SetSize³Command(*this, h);
    }
    
    void SetSize³Command::init_meta()
    {
        auto w = writer<SetSize³Command>();
        w.description("Set Size Command in 3D");
        w.property("x", &SetSize³Command::x).tag(kTag_Log);
        w.property("y", &SetSize³Command::y).tag(kTag_Log);
        w.property("z", &SetSize³Command::z).tag(kTag_Log);
        w.property("size", &SetSize³Command::m_size).tag(kTag_Save);
    }
}
