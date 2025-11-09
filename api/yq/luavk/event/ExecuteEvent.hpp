////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/luavk/event/LuaEvent.hpp>

namespace yq::lua {
    class ExecuteEvent : public LuaEvent {
        YQ_OBJECT_DECLARE(ExecuteEvent, LuaEvent)
    public:
        ExecuteEvent(const Header&, std::string&& out, std::string&& warn, std::string&& err, const std::error_code&);
        virtual tachyon::PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        const std::string&              output() const { return m_output; }
        const std::string&              warning() const { return m_warning; }
        const std::string&              error() const { return m_error; }
        const std::error_code&          error_code() const { return m_errorCode; }

    protected:
        ExecuteEvent(const ExecuteEvent&, const Header&);
        virtual ~ExecuteEvent();
        
    private:

        std::string             m_output;
        std::string             m_warning;
        std::string             m_error;
        std::error_code         m_errorCode;

        ExecuteEvent(const ExecuteEvent&) = delete;
        ExecuteEvent(ExecuteEvent&&) = delete;
        ExecuteEvent& operator=(const ExecuteEvent&) = delete;
        ExecuteEvent& operator=(ExecuteEvent&&) = delete;
    };
}
