////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/luavk/event/ExecuteEvent.hpp>
#include <filesystem>

namespace yq::lua {
    class ExecuteFileEvent : public ExecuteEvent {
        YQ_OBJECT_DECLARE(ExecuteFileEvent, ExecuteEvent)
    public:
        ExecuteFileEvent(const Header&, const std::filesystem::path&, std::string&& out, std::string&& warn, std::string&& err, const std::error_code&);
        virtual tachyon::PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        const std::filesystem::path&    file() const { return m_file; }

    protected:
        ExecuteFileEvent(const ExecuteFileEvent&, const Header&);
        virtual ~ExecuteFileEvent();
        
    private:

        std::filesystem::path   m_file;

        ExecuteFileEvent(const ExecuteFileEvent&) = delete;
        ExecuteFileEvent(ExecuteFileEvent&&) = delete;
        ExecuteFileEvent& operator=(const ExecuteFileEvent&) = delete;
        ExecuteFileEvent& operator=(ExecuteFileEvent&&) = delete;
    };
}
