////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/luavk/request/LuaRequest.hpp>

namespace yq::lua {
    class ExecuteStringRequest : public LuaRequest {
        YQ_OBJECT_DECLARE(ExecuteStringRequest, LuaRequest)
    public:
        ExecuteStringRequest(const Header&, std::string_view);
        virtual tachyon::PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        const std::string&  text() const { return m_text; }

    protected:
        ExecuteStringRequest(const ExecuteStringRequest&, const Header&);
        virtual ~ExecuteStringRequest();
        
    private:

        std::string         m_text;

        ExecuteStringRequest(const ExecuteStringRequest&) = delete;
        ExecuteStringRequest(ExecuteStringRequest&&) = delete;
        ExecuteStringRequest& operator=(const ExecuteStringRequest&) = delete;
        ExecuteStringRequest& operator=(ExecuteStringRequest&&) = delete;
    };
}
