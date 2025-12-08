////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SubscribeCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

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

    void SubscribeCommand::init_meta()
    {
        auto w = writer<SubscribeCommand>();
        w.description("Subscribe Command");
    }
}
