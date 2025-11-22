////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "LuaExecuteReply.hpp"
#include <yq/tachyon/api/ReplyMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::LuaExecuteReply)

namespace yq::tachyon {

    LuaExecuteReply::LuaExecuteReply(const Header&h, const RequestCPtr& rq, std::string&& out, std::string&& warn, std::string&& err, const std::error_code&ec) :
        LuaReply(h, rq), m_output(std::move(out)), m_warning(std::move(warn)), m_error(std::move(err)), m_errorCode(ec)
    {
    }

    LuaExecuteReply::LuaExecuteReply(const LuaExecuteReply& cp, const Header& h) : 
        LuaReply(cp, h), m_output(cp.m_output), m_warning(cp.m_warning), m_error(cp.m_error), m_errorCode(cp.m_errorCode)
    {
    }
    
    LuaExecuteReply::~LuaExecuteReply()
    {
    }

    tachyon::PostCPtr    LuaExecuteReply::clone(rebind_k, const Header&h) const 
    {
        return new LuaExecuteReply(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void LuaExecuteReply::init_meta()
    {
        auto w = writer<LuaExecuteReply>();
        w.description("Lua Execute Reply");
        w.property("output", &LuaExecuteReply::m_output);
        w.property("warning", &LuaExecuteReply::m_warning);
        w.property("error", &LuaExecuteReply::m_error);
    }
}
