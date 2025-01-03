////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/TachyonUnsnoopCommand.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::TachyonUnsnoopCommand)

namespace yq::tachyon {
    TachyonUnsnoopCommand::TachyonUnsnoopCommand(TachyonID t, TachyonID l,  const Param& p) :
        TachyonCommand(t, p), m_listener(l)
    {
    }

    TachyonUnsnoopCommand::~TachyonUnsnoopCommand()
    {
    }
    
    void TachyonUnsnoopCommand::init_info()
    {
        auto w = writer<TachyonUnsnoopCommand>();
        w.description("Tachyon Unsnoop Command");
    }
}