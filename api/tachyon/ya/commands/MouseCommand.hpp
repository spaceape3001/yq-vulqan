////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/msg/Command.hpp>

namespace yq::tachyon {
    class MouseCommand : public Command {
        YQ_OBJECT_DECLARE(MouseCommand, Command)
    public:

        static void init_info();

    protected:
    
        MouseCommand(const Header&);
        MouseCommand(const MouseCommand&, const Header&);
        virtual ~MouseCommand();
        
    private:
        MouseCommand(const MouseCommand&) = delete;
        MouseCommand(MouseCommand&&) = delete;
        MouseCommand& operator=(const MouseCommand&) = delete;
        MouseCommand& operator=(MouseCommand&&) = delete;
    };
}
