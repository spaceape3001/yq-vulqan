////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "TachyonProxyCommand.hpp"
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::TachyonProxyCommand)

namespace yq::tachyon {
    TachyonProxyCommand::TachyonProxyCommand(TachyonID tid, ProxyFN&&fn, const Param& p) : 
        TachyonCommand(tid, p), m_function(std::move(fn))
    {
    }
    
    TachyonProxyCommand::~TachyonProxyCommand()
    {
    }
    
    void TachyonProxyCommand::init_info()
    {
        auto w = writer<TachyonProxyCommand>();
        w.description("Tachyon Proxy Command");
    }
}
