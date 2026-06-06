////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Command.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class EntityCommand : public Command {
        YQ_OBJECT_DECLARE(EntityCommand, Command)
    public:
    
        static void init_meta();

    protected:
        EntityCommand(const Header&);
        EntityCommand(const EntityCommand&, const Header&);
        ~EntityCommand();
        
    private:
        EntityCommand(const EntityCommand&) = delete;
        EntityCommand(EntityCommand&&) = delete;
        EntityCommand& operator=(const EntityCommand&) = delete;
        EntityCommand& operator=(EntityCommand&&) = delete;
    };
}
