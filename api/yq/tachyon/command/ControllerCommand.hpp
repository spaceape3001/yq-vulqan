////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Command.hpp>

namespace yq::tachyon {
    class ControllerCommand : public Command {
        YQ_OBJECT_DECLARE(ControllerCommand, Command)
    public:
    
        static void init_meta();
    
    protected:
        ControllerCommand(const Header&);
        ControllerCommand(const ControllerCommand&, const Header&);
        ~ControllerCommand();
        
    private:
        ControllerCommand(const ControllerCommand&) = delete;
        ControllerCommand(ControllerCommand&&) = delete;
        ControllerCommand& operator=(const ControllerCommand&) = delete;
        ControllerCommand& operator=(ControllerCommand&&) = delete;
    };
}
