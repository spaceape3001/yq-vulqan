////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/luavk/request/LuaRequest.hpp>

namespace yq::lua {
    class LuaExecuteStringRequest : public LuaRequest {
        YQ_OBJECT_DECLARE(LuaExecuteStringRequest, LuaRequest)
    public:
        LuaExecuteStringRequest(const Header&, std::string_view);
        virtual tachyon::PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        const std::string&  text() const { return m_text; }

    protected:
        LuaExecuteStringRequest(const LuaExecuteStringRequest&, const Header&);
        virtual ~LuaExecuteStringRequest();
        
    private:

        std::string         m_text;

        LuaExecuteStringRequest(const LuaExecuteStringRequest&) = delete;
        LuaExecuteStringRequest(LuaExecuteStringRequest&&) = delete;
        LuaExecuteStringRequest& operator=(const LuaExecuteStringRequest&) = delete;
        LuaExecuteStringRequest& operator=(LuaExecuteStringRequest&&) = delete;
    };
}
