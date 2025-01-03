////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/TachyonCommand.hpp>
#include <yt/typedef/proxy.hpp>

namespace yq::tachyon {
    class TachyonProxyCommand : public TachyonCommand {
        YQ_OBJECT_DECLARE(TachyonProxyCommand, TachyonCommand)
    public:
        TachyonProxyCommand(TachyonID, ProxyFN&&, const Param& p = {});
        ~TachyonProxyCommand();
        
        const ProxyFN&  function() const { return m_function; }
        
        static void init_info();
    private:
        ProxyFN     m_function;
    };
}
