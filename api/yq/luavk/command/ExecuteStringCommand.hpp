////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/luavk/command/LuaCommand.hpp>

namespace yq::lua {
    class ExecuteStringCommand : public LuaCommand {
        YQ_OBJECT_DECLARE(ExecuteStringCommand, LuaCommand)
    public:
        ExecuteStringCommand(const Header&, std::string_view);
        virtual tachyon::PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        const std::string&  text() const { return m_text; }

    protected:
        ExecuteStringCommand(const ExecuteStringCommand&, const Header&);
        virtual ~ExecuteStringCommand();
        
    private:

        std::string         m_text;

        ExecuteStringCommand(const ExecuteStringCommand&) = delete;
        ExecuteStringCommand(ExecuteStringCommand&&) = delete;
        ExecuteStringCommand& operator=(const ExecuteStringCommand&) = delete;
        ExecuteStringCommand& operator=(ExecuteStringCommand&&) = delete;
    };
}
