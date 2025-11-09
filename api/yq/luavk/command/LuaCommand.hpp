////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Command.hpp>
#include <yq/tachyon/typedef/spatial.hpp>

namespace yq::lua {

    //! Instructs an object to set it's position
    class LuaCommand : public tachyon::Command {
        YQ_OBJECT_DECLARE(LuaCommand, tachyon::Command)
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
