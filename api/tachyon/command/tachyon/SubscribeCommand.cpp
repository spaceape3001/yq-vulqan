////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/tachyon/SubscribeCommand.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SubscribeCommand)

namespace yq::tachyon {
    SubscribeCommand::SubscribeCommand(const Header& h, TypedID l, MGF g) :
        TachyonCommand(h), m_listener(l), m_groups(g)
    {
    }

    SubscribeCommand::SubscribeCommand(const SubscribeCommand&cp, const Header&h) : 
        TachyonCommand(cp, h), m_listener(cp.m_listener), m_groups(cp.m_groups)
    {
    }

    SubscribeCommand::~SubscribeCommand()
    {
    }
    
    PostCPtr    SubscribeCommand::clone(rebind_k, const Header&h) const 
    {
        return new SubscribeCommand(*this, h);
    }

    void SubscribeCommand::init_info()
    {
        auto w = writer<SubscribeCommand>();
        w.description("Subscribe Command");
    }
}
