////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/tachyon/UnsnoopCommand.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UnsnoopCommand)

namespace yq::tachyon {
    UnsnoopCommand::UnsnoopCommand(const Header& h, TypedID l) :
        TachyonCommand(h), m_listener(l)
    {
    }

    UnsnoopCommand::UnsnoopCommand(const UnsnoopCommand& cp, const Header& h) :
        TachyonCommand(cp, h), m_listener(cp.m_listener)
    {
    }

    UnsnoopCommand::~UnsnoopCommand()
    {
    }
    
    PostCPtr    UnsnoopCommand::clone(rebind_k, const Header& h) const 
    {
        return new UnsnoopCommand(*this, h);
    }

    void UnsnoopCommand::init_info()
    {
        auto w = writer<UnsnoopCommand>();
        w.description("Unsnoop Command");
    }
}
