////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/tachyon/SnoopCommand.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SnoopCommand)

namespace yq::tachyon {
    SnoopCommand::SnoopCommand(const Header&h, TypedID l) :
        TachyonCommand(h), m_listener(l)
    {
    }

    SnoopCommand::SnoopCommand(const SnoopCommand& cp, const Header&h) : 
        TachyonCommand(cp, h), m_listener(cp.m_listener)
    {
    }

    SnoopCommand::~SnoopCommand()
    {
    }

    PostCPtr    SnoopCommand::clone(rebind_k, const Header&h) const 
    {
        return new SnoopCommand(*this, h);
    }
    
    void SnoopCommand::init_info()
    {
        auto w = writer<SnoopCommand>();
        w.description("Snoop Command");
    }
}
