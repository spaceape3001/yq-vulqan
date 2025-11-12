////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/luavk/request/ExecuteStringRequest.hpp>
#include <yq/tachyon/api/RequestMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::lua::ExecuteStringRequest)

namespace yq::lua {

    ExecuteStringRequest::ExecuteStringRequest(const Header&h, std::string_view v) : LuaRequest(h), m_text(v)
    {
    }

    ExecuteStringRequest::ExecuteStringRequest(const ExecuteStringRequest& cp, const Header& h) : 
        LuaRequest(cp, h), m_text(cp.m_text)
    {
    }
    
    ExecuteStringRequest::~ExecuteStringRequest()
    {
    }

    tachyon::PostCPtr    ExecuteStringRequest::clone(rebind_k, const Header&h) const 
    {
        return new ExecuteStringRequest(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ExecuteStringRequest::init_meta()
    {
        auto w = writer<ExecuteStringRequest>();
        w.description("Lua Execute String Request");
        w.property("text", &ExecuteStringRequest::m_text);
    }
}
