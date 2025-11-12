////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Request.hpp>
#include <yq/tachyon/typedef/spatial.hpp>

namespace yq::lua {

    //! Instructs an object to set it's position
    class LuaRequest : public tachyon::Request {
        YQ_OBJECT_DECLARE(LuaRequest, tachyon::Request)
    public:
    
        static void init_meta();

    protected:
        LuaRequest(const Header&);
        LuaRequest(const LuaRequest&, const Header&);
        ~LuaRequest();
        
    private:
        LuaRequest(const LuaRequest&) = delete;
        LuaRequest(LuaRequest&&) = delete;
        LuaRequest& operator=(const LuaRequest&) = delete;
        LuaRequest& operator=(LuaRequest&&) = delete;
    };
}
