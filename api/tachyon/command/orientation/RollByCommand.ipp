////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/orientation/RollByCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>
#include <yq/unit/metatype.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::RollByCommand)

namespace yq::tachyon {
    RollByCommand::RollByCommand(const Header&h, Radian θ) : 
        OrientationCommand(h), m_θ(θ)
    {
    }
    
    RollByCommand::RollByCommand(const RollByCommand& cp, const Header&h) : 
        OrientationCommand(cp, h), m_θ(cp.m_θ)
    {
    }

    RollByCommand::~RollByCommand()
    {
    }

    PostCPtr    RollByCommand::clone(rebind_k, const Header&h) const 
    {
        return new RollByCommand(*this, h);
    }
    
    void RollByCommand::init_info()
    {
        auto w = writer<RollByCommand>();
        w.description("Roll By Command");
        w.property("θ", &RollByCommand::θ);
    }
}
