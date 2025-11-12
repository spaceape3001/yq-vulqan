////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/luavk/request/LuaRequest.hpp>
#include <yq/tachyon/api/RequestMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::lua::LuaRequest)

namespace yq::lua {
    LuaRequest::LuaRequest(const Header& h) : tachyon::Request(h)
    {
    }
    
    LuaRequest::LuaRequest(const LuaRequest&cp, const Header&h) : tachyon::Request(cp, h)
    {
    }

    LuaRequest::~LuaRequest()
    {
    }
    
    void LuaRequest::init_meta()
    {
        auto w = writer<LuaRequest>();
        w.abstract();
        w.description("Lua Request");
    }
}
