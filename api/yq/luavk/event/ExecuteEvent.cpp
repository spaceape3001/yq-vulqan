////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/luavk/event/ExecuteEvent.hpp>
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::lua::ExecuteEvent)

namespace yq::lua {

    ExecuteEvent::ExecuteEvent(const Header&h, std::string&& out, std::string&& warn, std::string&& err, const std::error_code&ec) :
        LuaEvent(h), m_output(std::move(out)), m_warning(std::move(warn)), m_error(std::move(err)), m_errorCode(ec)
    {
    }

    ExecuteEvent::ExecuteEvent(const ExecuteEvent& cp, const Header& h) : 
        LuaEvent(cp, h), m_output(cp.m_output), m_warning(cp.m_warning), m_error(cp.m_error), m_errorCode(cp.m_errorCode)
    {
    }
    
    ExecuteEvent::~ExecuteEvent()
    {
    }

    tachyon::PostCPtr    ExecuteEvent::clone(rebind_k, const Header&h) const 
    {
        return new ExecuteEvent(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ExecuteEvent::init_meta()
    {
        auto w = writer<ExecuteEvent>();
        w.description("Lua Execute Event");
        w.property("output", &ExecuteEvent::m_output);
        w.property("warning", &ExecuteEvent::m_warning);
        w.property("error", &ExecuteEvent::m_error);
    }
}
