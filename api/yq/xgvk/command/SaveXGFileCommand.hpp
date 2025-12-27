////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/xgvk/command/XGVkCommand.hpp>
#include <filesystem>

namespace yq::tachyon {
    class SaveXGFileCommand : public XGVkCommand {
        YQ_OBJECT_DECLARE(SaveXGFileCommand, XGVkCommand)
    public:
        SaveXGFileCommand(const Header&, const std::filesystem::path&);
        virtual tachyon::PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        const std::filesystem::path&  file() const { return m_file; }

    protected:
        SaveXGFileCommand(const SaveXGFileCommand&, const Header&);
        virtual ~SaveXGFileCommand();
        
    private:

        std::filesystem::path         m_file;

        SaveXGFileCommand(const SaveXGFileCommand&) = delete;
        SaveXGFileCommand(SaveXGFileCommand&&) = delete;
        SaveXGFileCommand& operator=(const SaveXGFileCommand&) = delete;
        SaveXGFileCommand& operator=(SaveXGFileCommand&&) = delete;
    };
}
