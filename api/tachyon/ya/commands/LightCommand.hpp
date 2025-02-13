////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/msg/Command.hpp>

namespace yq::tachyon {
    class Light;

    class LightCommand : public Command {
        YQ_OBJECT_DECLARE(LightCommand, Command)
    public:

        static void init_info();

    protected:
        LightCommand(const Header&);
        LightCommand(const LightCommand&, const Header& h);
        virtual ~LightCommand();
        
    private:
        LightCommand(const LightCommand&) = delete;
        LightCommand(LightCommand&&) = delete;
        LightCommand& operator=(const LightCommand&) = delete;
        LightCommand& operator=(LightCommand&&) = delete;
    };
}
