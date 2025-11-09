////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/luavk/command/LuaCommand.hpp>
#include <filesystem>

namespace yq::lua {
    class ExecuteFileCommand : public LuaCommand {
        YQ_OBJECT_DECLARE(ExecuteFileCommand, LuaCommand)
    public:
        ExecuteFileCommand(const Header&, const std::filesystem::path&);
        virtual tachyon::PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        const std::filesystem::path&  file() const { return m_file; }

    protected:
        ExecuteFileCommand(const ExecuteFileCommand&, const Header&);
        virtual ~ExecuteFileCommand();
        
    private:

        std::filesystem::path         m_file;

        ExecuteFileCommand(const ExecuteFileCommand&) = delete;
        ExecuteFileCommand(ExecuteFileCommand&&) = delete;
        ExecuteFileCommand& operator=(const ExecuteFileCommand&) = delete;
        ExecuteFileCommand& operator=(ExecuteFileCommand&&) = delete;
    };
}
