////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/luavk/event/ExecuteStringEvent.hpp>
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::lua::ExecuteStringEvent)

namespace yq::lua {

    ExecuteStringEvent::ExecuteStringEvent(const Header&h, std::string_view cmd, std::string&& out, std::string&& warn, std::string&& err, const std::error_code& ec) :
        ExecuteEvent(h, std::move(out), std::move(warn), std::move(err), ec), m_command(cmd)
    {
    }
    
    ExecuteStringEvent::ExecuteStringEvent(const ExecuteStringEvent& cp, const Header& h) : 
        ExecuteEvent(cp, h), m_command(cp.m_command)
    {
    }
    
    ExecuteStringEvent::~ExecuteStringEvent()
    {
    }

    tachyon::PostCPtr    ExecuteStringEvent::clone(rebind_k, const Header&h) const 
    {
        return new ExecuteStringEvent(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ExecuteStringEvent::init_meta()
    {
        auto w = writer<ExecuteStringEvent>();
        w.description("Lua Execute String Event");
        w.property("command", &ExecuteStringEvent::m_command);
    }
}
