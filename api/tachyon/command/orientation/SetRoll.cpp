////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/orientation/SetRoll.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>
#include <yq/unit/metatype.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetRoll)

namespace yq::tachyon {
    SetRoll::SetRoll(const Header& h) : OrientationCommand(h)
    {
    }

    SetRoll::SetRoll(const Header&h, Radian θ) : 
        OrientationCommand(h), m_θ(θ)
    {
    }
    
    SetRoll::SetRoll(const SetRoll& cp, const Header&h) : 
        OrientationCommand(cp, h), m_θ(cp.m_θ)
    {
    }

    SetRoll::~SetRoll()
    {
    }

    PostCPtr    SetRoll::clone(rebind_k, const Header&h) const 
    {
        return new SetRoll(*this, h);
    }
    
    void SetRoll::init_info()
    {
        auto w = writer<SetRoll>();
        w.description("Set Roll Command");
        w.property("θ", &SetRoll::m_θ).tag(kTag_Log).tag(kTag_Save);
    }
}
