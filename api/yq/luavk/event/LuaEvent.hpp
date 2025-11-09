////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Event.hpp>
#include <yq/tachyon/typedef/spatial.hpp>

namespace yq::lua {

    //! Instructs an object to set it's position
    class LuaEvent : public tachyon::Event {
        YQ_OBJECT_DECLARE(LuaEvent, tachyon::Event)
    public:
    
        static void init_meta();

    protected:
        LuaEvent(const Header&);
        LuaEvent(const LuaEvent&, const Header&);
        ~LuaEvent();
        
    private:
        LuaEvent(const LuaEvent&) = delete;
        LuaEvent(LuaEvent&&) = delete;
        LuaEvent& operator=(const LuaEvent&) = delete;
        LuaEvent& operator=(LuaEvent&&) = delete;
    };
}
