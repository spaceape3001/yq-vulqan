////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/TachyonSnoopCommand.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::TachyonSnoopCommand)

namespace yq::tachyon {
    TachyonSnoopCommand::TachyonSnoopCommand(TachyonID t, TachyonID l,  const Param& p) :
        TachyonCommand(t, p), m_listener(l)
    {
    }

    TachyonSnoopCommand::~TachyonSnoopCommand()
    {
    }
    
    void TachyonSnoopCommand::init_info()
    {
        auto w = writer<TachyonSnoopCommand>();
        w.description("Tachyon Snoop Command");
    }
}
