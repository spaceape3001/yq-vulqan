////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Reply.hpp>
#include <yq/tachyon/typedef/spatial.hpp>

namespace yq::lua {

    //! Instructs an object to set it's position
    class LuaReply : public tachyon::Reply {
        YQ_OBJECT_DECLARE(LuaReply, tachyon::Reply)
    public:
    
        static void init_meta();

    protected:
        LuaReply(const Header&, const tachyon::RequestCPtr&);
        LuaReply(const LuaReply&, const Header&);
        ~LuaReply();
        
    private:
        LuaReply(const LuaReply&) = delete;
        LuaReply(LuaReply&&) = delete;
        LuaReply& operator=(const LuaReply&) = delete;
        LuaReply& operator=(LuaReply&&) = delete;
    };
}
