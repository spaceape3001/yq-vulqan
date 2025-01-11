////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/SetPitch.hpp>
#include <yt/msg/CommandInfoWriter.hpp>
#include <yq/unit/metatype.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetPitch)

namespace yq::tachyon {
    SetPitch::SetPitch(const Header&h) : 
        SpatialCommand(h)
    {
    }
    
    SetPitch::SetPitch(const Header&h, Radian θ) : 
        SpatialCommand(h), m_θ(θ)
    {
    }

    SetPitch::SetPitch(const SetPitch& cp, const Header&h) : 
        SpatialCommand(cp, h), m_θ(cp.m_θ)
    {
    }

    SetPitch::~SetPitch()
    {
    }

    PostCPtr    SetPitch::clone(rebind_k, const Header&h) const 
    {
        return new SetPitch(*this, h);
    }
    
    void SetPitch::init_info()
    {
        auto w = writer<SetPitch>();
        w.description("Set Pitch Command");
        w.property("θ", &SetPitch::m_θ).tag(kTag_Log).tag(kTag_Save);
    }
}
