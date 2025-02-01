////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/msg/Command.hpp>
#include <yt/typedef/spatial.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class SimCommand : public Command {
        YQ_OBJECT_DECLARE(SimCommand, Command)
    public:
    
        static void init_info();

    protected:
        SimCommand(const Header&);
        SimCommand(const SimCommand&, const Header&);
        ~SimCommand();
        
    private:
        SimCommand(const SimCommand&) = delete;
        SimCommand(SimCommand&&) = delete;
        SimCommand& operator=(const SimCommand&) = delete;
        SimCommand& operator=(SimCommand&&) = delete;
    };
}
