////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/api/RequestMetaWriter.hpp>
#include <yq/tachyon/request/lua/LuaExecuteStringRequest.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::LuaExecuteStringRequest)

namespace yq::tachyon {

    LuaExecuteStringRequest::LuaExecuteStringRequest(const Header&h, std::string_view v) : LuaRequest(h), m_text(v)
    {
    }

    LuaExecuteStringRequest::LuaExecuteStringRequest(const LuaExecuteStringRequest& cp, const Header& h) : 
        LuaRequest(cp, h), m_text(cp.m_text)
    {
    }
    
    LuaExecuteStringRequest::~LuaExecuteStringRequest()
    {
    }

    tachyon::PostCPtr    LuaExecuteStringRequest::clone(rebind_k, const Header&h) const 
    {
        return new LuaExecuteStringRequest(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void LuaExecuteStringRequest::init_meta()
    {
        auto w = writer<LuaExecuteStringRequest>();
        w.description("Lua LuaExecute String Request");
        w.property("text", &LuaExecuteStringRequest::m_text);
    }
}
