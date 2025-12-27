////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/command/FileCommand.hpp>
#include <filesystem>
#include <yq/net/Url.hpp>

namespace yq::tachyon {
    class SaveAsTSXFileCommand : public FileCommand {
        YQ_OBJECT_DECLARE(SaveAsTSXFileCommand, FileCommand)
    public:
        SaveAsTSXFileCommand(const Header&, const std::filesystem::path&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        const std::filesystem::path& filepath() const { return m_filepath; }
        
        //const Url&     url() const { return m_url; }

    protected:
        SaveAsTSXFileCommand(const SaveAsTSXFileCommand&, const Header&);
        virtual ~SaveAsTSXFileCommand();
        
    private:
    
        std::filesystem::path m_filepath;
        //Url    m_url;

        SaveAsTSXFileCommand(const SaveAsTSXFileCommand&) = delete;
        SaveAsTSXFileCommand(SaveAsTSXFileCommand&&) = delete;
        SaveAsTSXFileCommand& operator=(const SaveAsTSXFileCommand&) = delete;
        SaveAsTSXFileCommand& operator=(SaveAsTSXFileCommand&&) = delete;
    };
}
