////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/luavk/LuaRequest.hpp>
#include <yq/tachyon/api/RequestMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::LuaRequest)

namespace yq::tachyon {
    LuaRequest::LuaRequest(const Header& h) : Request(h)
    {
    }
    
    LuaRequest::LuaRequest(const LuaRequest&cp, const Header&h) : Request(cp, h)
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
