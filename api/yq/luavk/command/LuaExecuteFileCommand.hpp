////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/luavk/command/LuaCommand.hpp>
#include <filesystem>

namespace yq::tachyon {
    class LuaExecuteFileCommand : public LuaCommand {
        YQ_OBJECT_DECLARE(LuaExecuteFileCommand, LuaCommand)
    public:
        LuaExecuteFileCommand(const Header&, const std::filesystem::path&);
        virtual tachyon::PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        const std::filesystem::path&  file() const { return m_file; }

    protected:
        LuaExecuteFileCommand(const LuaExecuteFileCommand&, const Header&);
        virtual ~LuaExecuteFileCommand();
        
    private:

        std::filesystem::path         m_file;

        LuaExecuteFileCommand(const LuaExecuteFileCommand&) = delete;
        LuaExecuteFileCommand(LuaExecuteFileCommand&&) = delete;
        LuaExecuteFileCommand& operator=(const LuaExecuteFileCommand&) = delete;
        LuaExecuteFileCommand& operator=(LuaExecuteFileCommand&&) = delete;
    };
}
