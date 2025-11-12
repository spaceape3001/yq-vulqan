////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/luavk/request/LuaRequest.hpp>
#include <filesystem>

namespace yq::lua {
    class ExecuteFileRequest : public LuaRequest {
        YQ_OBJECT_DECLARE(ExecuteFileRequest, LuaRequest)
    public:
        ExecuteFileRequest(const Header&, const std::filesystem::path&);
        virtual tachyon::PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        const std::filesystem::path&  file() const { return m_file; }

    protected:
        ExecuteFileRequest(const ExecuteFileRequest&, const Header&);
        virtual ~ExecuteFileRequest();
        
    private:

        std::filesystem::path         m_file;

        ExecuteFileRequest(const ExecuteFileRequest&) = delete;
        ExecuteFileRequest(ExecuteFileRequest&&) = delete;
        ExecuteFileRequest& operator=(const ExecuteFileRequest&) = delete;
        ExecuteFileRequest& operator=(ExecuteFileRequest&&) = delete;
    };
}
