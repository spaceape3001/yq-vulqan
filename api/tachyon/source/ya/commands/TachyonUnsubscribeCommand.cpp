////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/TachyonUnsubscribeCommand.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::TachyonUnsubscribeCommand)

namespace yq::tachyon {
    TachyonUnsubscribeCommand::TachyonUnsubscribeCommand(TachyonID t, TachyonID l, MGF g, const Param& p) :
        TachyonCommand(t, p), m_listener(l), m_groups(g)
    {
    }

    TachyonUnsubscribeCommand::~TachyonUnsubscribeCommand()
    {
    }
    
    void TachyonUnsubscribeCommand::init_info()
    {
        auto w = writer<TachyonUnsubscribeCommand>();
        w.description("Tachyon Unsubscribe Command");
    }
}
