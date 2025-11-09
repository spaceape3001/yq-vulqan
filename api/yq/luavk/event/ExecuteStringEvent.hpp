////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/luavk/event/ExecuteEvent.hpp>

namespace yq::lua {
    class ExecuteStringEvent : public ExecuteEvent {
        YQ_OBJECT_DECLARE(ExecuteStringEvent, ExecuteEvent)
    public:
        ExecuteStringEvent(const Header&, std::string_view, std::string&& out, std::string&& warn, std::string&& err, const std::error_code&);
        virtual tachyon::PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        const std::string&      command() const { return m_command; }

    protected:
        ExecuteStringEvent(const ExecuteStringEvent&, const Header&);
        virtual ~ExecuteStringEvent();
        
    private:

        std::string         m_command;

        ExecuteStringEvent(const ExecuteStringEvent&) = delete;
        ExecuteStringEvent(ExecuteStringEvent&&) = delete;
        ExecuteStringEvent& operator=(const ExecuteStringEvent&) = delete;
        ExecuteStringEvent& operator=(ExecuteStringEvent&&) = delete;
    };
}
