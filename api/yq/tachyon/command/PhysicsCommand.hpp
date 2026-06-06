////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Command.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class PhysicsCommand : public Command {
        YQ_OBJECT_DECLARE(PhysicsCommand, Command)
    public:
    
        static void init_meta();

    protected:
        PhysicsCommand(const Header&);
        PhysicsCommand(const PhysicsCommand&, const Header&);
        ~PhysicsCommand();
        
    private:
        PhysicsCommand(const PhysicsCommand&) = delete;
        PhysicsCommand(PhysicsCommand&&) = delete;
        PhysicsCommand& operator=(const PhysicsCommand&) = delete;
        PhysicsCommand& operator=(PhysicsCommand&&) = delete;
    };
}
