////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/tachyon/UnsubscribeCommand.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::UnsubscribeCommand)

namespace yq::tachyon {
    UnsubscribeCommand::UnsubscribeCommand(const Header&h, TypedID l, MGF g) :
        TachyonCommand(h), m_listener(l), m_groups(g)
    {
    }

    UnsubscribeCommand::UnsubscribeCommand(const UnsubscribeCommand&cp, const Header&h) :
        TachyonCommand(cp, h), m_listener(cp.m_listener), m_groups(cp.m_groups)
    {
    }

    UnsubscribeCommand::~UnsubscribeCommand()
    {
    }

    PostCPtr    UnsubscribeCommand::clone(rebind_k, const Header&h) const
    {
        return new UnsubscribeCommand(*this, h);
    }
    
    void UnsubscribeCommand::init_info()
    {
        auto w = writer<UnsubscribeCommand>();
        w.description("Unsubscribe Command");
    }
}
