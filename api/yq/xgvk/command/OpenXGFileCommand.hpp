////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/xgvk/command/XGVkCommand.hpp>
#include <filesystem>

namespace yq::tachyon {
    class OpenXGFileCommand : public XGVkCommand {
        YQ_OBJECT_DECLARE(OpenXGFileCommand, XGVkCommand)
    public:
        OpenXGFileCommand(const Header&, const std::filesystem::path&);
        virtual tachyon::PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        const std::filesystem::path&  file() const { return m_file; }

    protected:
        OpenXGFileCommand(const OpenXGFileCommand&, const Header&);
        virtual ~OpenXGFileCommand();
        
    private:

        std::filesystem::path         m_file;

        OpenXGFileCommand(const OpenXGFileCommand&) = delete;
        OpenXGFileCommand(OpenXGFileCommand&&) = delete;
        OpenXGFileCommand& operator=(const OpenXGFileCommand&) = delete;
        OpenXGFileCommand& operator=(OpenXGFileCommand&&) = delete;
    };
}
