////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/scale/SetScale3.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetScale³)

namespace yq::tachyon {
    SetScale³::SetScale³(const Header& h) : 
        ScaleCommand(h)
    {
    }

    SetScale³::SetScale³(const Header& h, const Vector3D& v) : 
        ScaleCommand(h), m_scale(v)
    {
    }

    SetScale³::SetScale³(const SetScale³& cp, const Header& h) : 
        ScaleCommand(cp, h), m_scale(cp.m_scale)
    {
    }
    
    SetScale³::~SetScale³()
    {
    }

    PostCPtr    SetScale³::clone(rebind_k, const Header&h) const 
    {
        return new SetScale³(*this, h);
    }
    
    void SetScale³::init_info()
    {
        auto w = writer<SetScale³>();
        w.description("Set Scale Command");
        w.property("x", &SetScale³::x).tag(kTag_Log);
        w.property("y", &SetScale³::y).tag(kTag_Log);
        w.property("z", &SetScale³::z).tag(kTag_Log);
        w.property("scale", &SetScale³::m_scale).tag(kTag_Save);
    }
}
