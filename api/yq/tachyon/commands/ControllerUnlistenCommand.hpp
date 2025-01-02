////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/ControllerCommand.hpp>
#include <yt/typedef/tachyon.hpp>

namespace yq::tachyon {
    class ControllerUnlistenCommand : public ControllerCommand {
        YQ_OBJECT_DECLARE(ControllerUnlistenCommand, ControllerCommand)
    public:
    
        struct Param : public ControllerCommand::Param {
        };
    
        ControllerUnlistenCommand(Controller*, TachyonID, const Param& p = {});
        ControllerUnlistenCommand(ControllerID, TachyonID, const Param& p = {});
        virtual ~ControllerUnlistenCommand();
        
        static void init_info();
        
        TachyonID    tachyon() const { return m_tachyon; }
        
    private:
        TachyonID const  m_tachyon;
    };
}
