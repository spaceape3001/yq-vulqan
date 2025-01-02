////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/ControllerCommand.hpp>
#include <yt/typedef/tachyon.hpp>

namespace yq::tachyon {
    class ControllerUncontrolCommand : public ControllerCommand {
        YQ_OBJECT_DECLARE(ControllerUncontrolCommand, ControllerCommand)
    public:
    
        struct Param : public ControllerCommand::Param {
        };
    
        ControllerUncontrolCommand(Controller*, TachyonID, const Param& p = {});
        ControllerUncontrolCommand(ControllerID, TachyonID, const Param& p = {});
        virtual ~ControllerUncontrolCommand();
        
        static void init_info();
        
        TachyonID    tachyon() const { return m_tachyon; }
        
    private:
        TachyonID const  m_tachyon;
    };
}
