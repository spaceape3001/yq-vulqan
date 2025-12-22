////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Command.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class LuaCommand : public Command {
        YQ_OBJECT_DECLARE(LuaCommand, Command)
    public:
    
        static void init_meta();

    protected:
        LuaCommand(const Header&);
        LuaCommand(const LuaCommand&, const Header&);
        ~LuaCommand();
        
    private:
        LuaCommand(const LuaCommand&) = delete;
        LuaCommand(LuaCommand&&) = delete;
        LuaCommand& operator=(const LuaCommand&) = delete;
        LuaCommand& operator=(LuaCommand&&) = delete;
    };
}
