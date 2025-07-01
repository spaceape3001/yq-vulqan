////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/orientation/YawByCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>
#include <yq/unit/metatype.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::YawByCommand)

namespace yq::tachyon {
    YawByCommand::YawByCommand(const Header&h, Radian θ) : 
        OrientationCommand(h), m_θ(θ)
    {
    }

    
    YawByCommand::YawByCommand(const YawByCommand&cp, const Header&h) : OrientationCommand(cp, h), m_θ(cp.m_θ)
    {
    }
    
    YawByCommand::~YawByCommand()
    {
    }

    PostCPtr    YawByCommand::clone(rebind_k, const Header&h) const 
    { 
        return new YawByCommand(*this, h); 
    }
    
    void YawByCommand::init_info()
    {
        auto w = writer<YawByCommand>();
        w.description("Yaw By Command");
        w.property("θ", &YawByCommand::θ);
    }
}
