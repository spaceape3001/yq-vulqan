////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "TachyonDeleteCommand.hpp"
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::TachyonDeleteCommand)

namespace yq::tachyon {
    TachyonDeleteCommand::TachyonDeleteCommand(TachyonID t, const Param& p) : 
        TachyonCommand(t, p)
    {
    }
    
    TachyonDeleteCommand::TachyonDeleteCommand(Tachyon* t, const Param& p) : 
        TachyonCommand(t, p)
    {
    }

    TachyonDeleteCommand::~TachyonDeleteCommand()
    {
    }
    
    void TachyonDeleteCommand::init_info()
    {
        auto w = writer<TachyonDeleteCommand>();
        w.description("Tachyon Delete Command");
    }
}
