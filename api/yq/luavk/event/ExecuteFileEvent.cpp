////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/luavk/event/ExecuteFileEvent.hpp>
#include <yq/tachyon/api/EventMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::lua::ExecuteFileEvent)

namespace yq::lua {

    ExecuteFileEvent::ExecuteFileEvent(const Header&h, const std::filesystem::path&v, std::string&& out, std::string&& warn, std::string&& err, const std::error_code&ec) :
        ExecuteEvent(h, std::move(out), std::move(warn), std::move(err), ec), m_file(v)
    {
    }

    ExecuteFileEvent::ExecuteFileEvent(const ExecuteFileEvent& cp, const Header& h) : 
        ExecuteEvent(cp, h), m_file(cp.m_file)
    {
    }
    
    ExecuteFileEvent::~ExecuteFileEvent()
    {
    }

    tachyon::PostCPtr    ExecuteFileEvent::clone(rebind_k, const Header&h) const 
    {
        return new ExecuteFileEvent(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ExecuteFileEvent::init_meta()
    {
        auto w = writer<ExecuteFileEvent>();
        w.description("Lua Execute File Event");
        //w.property("file", &ExecuteFileEvent::m_file);  // TODO (file as an any)
    }
}
