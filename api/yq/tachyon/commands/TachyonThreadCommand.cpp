////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "TachyonThreadCommand.hpp"
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::TachyonThreadCommand)

namespace yq::tachyon {
    TachyonThreadCommand::TachyonThreadCommand(TachyonID t, ThreadID th, const Param& p) : 
        TachyonCommand(t, p), m_thread(th)
    {
    }
    
    TachyonThreadCommand::TachyonThreadCommand(Tachyon* t, ThreadID th, const Param& p) : 
        TachyonCommand(t, p), m_thread(th)
    {
    }

    TachyonThreadCommand::~TachyonThreadCommand()
    {
    }
    
    void TachyonThreadCommand::init_info()
    {
        auto w = writer<TachyonThreadCommand>();
        w.description("Tachyon Thread Command");
    }
}
