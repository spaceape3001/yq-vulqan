////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/ControllerCommand.hpp>
#include <yq/tachyon/typedef/tachyon.hpp>

namespace yq::tachyon {
    class ControllerListenCommand : public ControllerCommand {
        YQ_OBJECT_DECLARE(ControllerListenCommand, ControllerCommand)
    public:
    
        struct Param : public ControllerCommand::Param {
        };
    
        ControllerListenCommand(Controller*, TachyonID, const Param& p = {});
        ControllerListenCommand(ControllerID, TachyonID, const Param& p = {});
        virtual ~ControllerListenCommand();
        
        static void init_info();
        
        TachyonID    tachyon() const { return m_tachyon; }
        
    private:
        TachyonID const  m_tachyon;
    };
}
