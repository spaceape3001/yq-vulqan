////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/scale/SetScale3Command.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetScale³Command)

namespace yq::tachyon {
    SetScale³Command::SetScale³Command(const Header& h) : 
        ScaleCommand(h)
    {
    }

    SetScale³Command::SetScale³Command(const Header& h, const Vector3D& v) : 
        ScaleCommand(h), m_scale(v)
    {
    }

    SetScale³Command::SetScale³Command(const SetScale³Command& cp, const Header& h) : 
        ScaleCommand(cp, h), m_scale(cp.m_scale)
    {
    }
    
    SetScale³Command::~SetScale³Command()
    {
    }

    PostCPtr    SetScale³Command::clone(rebind_k, const Header&h) const 
    {
        return new SetScale³Command(*this, h);
    }
    
    void SetScale³Command::init_meta()
    {
        auto w = writer<SetScale³Command>();
        w.description("Set Scale Command");
        w.property("x", &SetScale³Command::x).tag(kTag_Log);
        w.property("y", &SetScale³Command::y).tag(kTag_Log);
        w.property("z", &SetScale³Command::z).tag(kTag_Log);
        w.property("scale", &SetScale³Command::m_scale).tag(kTag_Save);
    }
}
