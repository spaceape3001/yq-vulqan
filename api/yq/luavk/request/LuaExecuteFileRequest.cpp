////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "LuaExecuteFileRequest.hpp"
#include <yq/tachyon/api/RequestMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::LuaExecuteFileRequest)

namespace yq::tachyon {

    LuaExecuteFileRequest::LuaExecuteFileRequest(const Header&h, const std::filesystem::path& v) : LuaRequest(h), m_file(v)
    {
    }

    LuaExecuteFileRequest::LuaExecuteFileRequest(const LuaExecuteFileRequest& cp, const Header& h) : 
        LuaRequest(cp, h), m_file(cp.m_file)
    {
    }
    
    LuaExecuteFileRequest::~LuaExecuteFileRequest()
    {
    }

    tachyon::PostCPtr    LuaExecuteFileRequest::clone(rebind_k, const Header&h) const 
    {
        return new LuaExecuteFileRequest(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void LuaExecuteFileRequest::init_meta()
    {
        auto w = writer<LuaExecuteFileRequest>();
        w.description("Lua LuaExecute File Request");
        //w.property("file", &LuaExecuteFileRequest::m_file);  // TODO (file as an any)
    }
}
