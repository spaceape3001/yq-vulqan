////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/ControllerCommand.hpp>
#include <yt/typedef/tachyon.hpp>

namespace yq::tachyon {
    class ControllerControlCommand : public ControllerCommand {
        YQ_OBJECT_DECLARE(ControllerControlCommand, ControllerCommand)
    public:
    
        struct Param : public ControllerCommand::Param {
        };
    
        ControllerControlCommand(Controller*, TachyonID, const Param& p = {});
        ControllerControlCommand(ControllerID, TachyonID, const Param& p = {});
        virtual ~ControllerControlCommand();
        
        static void init_info();
        
        TachyonID    tachyon() const { return m_tachyon; }
        
    private:
        TachyonID const  m_tachyon;
    };
}
