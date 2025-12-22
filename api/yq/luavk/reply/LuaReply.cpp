////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "LuaReply.hpp"
#include <yq/tachyon/api/ReplyMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::LuaReply)

namespace yq::tachyon {
    LuaReply::LuaReply(const Header& h, const RequestCPtr&rq) : Reply(h, rq)
    {
    }
    
    LuaReply::LuaReply(const LuaReply&cp, const Header&h) : Reply(cp, h)
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
