////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/luavk/request/ExecuteFileRequest.hpp>
#include <yq/tachyon/api/RequestMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::lua::ExecuteFileRequest)

namespace yq::lua {

    ExecuteFileRequest::ExecuteFileRequest(const Header&h, const std::filesystem::path& v) : LuaRequest(h), m_file(v)
    {
    }

    ExecuteFileRequest::ExecuteFileRequest(const ExecuteFileRequest& cp, const Header& h) : 
        LuaRequest(cp, h), m_file(cp.m_file)
    {
    }
    
    ExecuteFileRequest::~ExecuteFileRequest()
    {
    }

    tachyon::PostCPtr    ExecuteFileRequest::clone(rebind_k, const Header&h) const 
    {
        return new ExecuteFileRequest(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ExecuteFileRequest::init_meta()
    {
        auto w = writer<ExecuteFileRequest>();
        w.description("Lua Execute File Request");
        //w.property("file", &ExecuteFileRequest::m_file);  // TODO (file as an any)
    }
}
