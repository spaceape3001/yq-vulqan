////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/luavk/reply/LuaReply.hpp>
#include <yq/tachyon/api/ReplyMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::lua::LuaReply)

namespace yq::lua {
    LuaReply::LuaReply(const Header& h, const tachyon::RequestCPtr&rq) : tachyon::Reply(h, rq)
    {
    }
    
    LuaReply::LuaReply(const LuaReply&cp, const Header&h) : tachyon::Reply(cp, h)
    {
    }

    LuaReply::~LuaReply()
    {
    }
    
    void LuaReply::init_meta()
    {
        auto w = writer<LuaReply>();
        w.abstract();
        w.description("Lua Reply");
    }
}
