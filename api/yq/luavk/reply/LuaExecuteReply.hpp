////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/luavk/reply/LuaReply.hpp>

namespace yq::tachyon {
    class LuaExecuteReply : public LuaReply {
        YQ_OBJECT_DECLARE(LuaExecuteReply, LuaReply)
    public:
        LuaExecuteReply(const Header&, const RequestCPtr&, std::string&& out, std::string&& warn, std::string&& err, const std::error_code&);
        virtual tachyon::PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        const std::string&              output() const { return m_output; }
        const std::string&              warning() const { return m_warning; }
        const std::string&              error() const { return m_error; }
        const std::error_code&          error_code() const { return m_errorCode; }

    protected:
        LuaExecuteReply(const LuaExecuteReply&, const Header&);
        virtual ~LuaExecuteReply();
        
    private:

        std::string             m_output;
        std::string             m_warning;
        std::string             m_error;
        std::error_code         m_errorCode;

        LuaExecuteReply(const LuaExecuteReply&) = delete;
        LuaExecuteReply(LuaExecuteReply&&) = delete;
        LuaExecuteReply& operator=(const LuaExecuteReply&) = delete;
        LuaExecuteReply& operator=(LuaExecuteReply&&) = delete;
    };
}
