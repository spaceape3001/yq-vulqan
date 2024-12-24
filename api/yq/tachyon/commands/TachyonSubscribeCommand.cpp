////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "TachyonSubscribeCommand.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::TachyonSubscribeCommand)

namespace yq::tachyon {
    TachyonSubscribeCommand::TachyonSubscribeCommand(TachyonID t, TachyonID l, MGF g, const Param& p) :
        TachyonCommand(t, p), m_listener(l), m_groups(g)
    {
    }

    TachyonSubscribeCommand::~TachyonSubscribeCommand()
    {
    }
    
    void TachyonSubscribeCommand::init_info()
    {
        auto w = writer<TachyonSubscribeCommand>();
        w.description("Tachyon Subscribe Command");
    }
}
