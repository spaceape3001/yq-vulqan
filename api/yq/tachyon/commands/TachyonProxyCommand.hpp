////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/TachyonCommand.hpp>
#include <yq/tachyon/typedef/proxy.hpp>

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
