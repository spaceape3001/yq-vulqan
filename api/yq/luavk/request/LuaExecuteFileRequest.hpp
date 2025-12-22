////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/luavk/request/LuaRequest.hpp>
#include <filesystem>

namespace yq::tachyon {
    class LuaExecuteFileRequest : public LuaRequest {
        YQ_OBJECT_DECLARE(LuaExecuteFileRequest, LuaRequest)
    public:
        LuaExecuteFileRequest(const Header&, const std::filesystem::path&);
        virtual tachyon::PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        const std::filesystem::path&  file() const { return m_file; }

    protected:
        LuaExecuteFileRequest(const LuaExecuteFileRequest&, const Header&);
        virtual ~LuaExecuteFileRequest();
        
    private:

        std::filesystem::path         m_file;

        LuaExecuteFileRequest(const LuaExecuteFileRequest&) = delete;
        LuaExecuteFileRequest(LuaExecuteFileRequest&&) = delete;
        LuaExecuteFileRequest& operator=(const LuaExecuteFileRequest&) = delete;
        LuaExecuteFileRequest& operator=(LuaExecuteFileRequest&&) = delete;
    };
}
