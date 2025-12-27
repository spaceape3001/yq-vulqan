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
    class ImportTSXFileCommand : public FileCommand {
        YQ_OBJECT_DECLARE(ImportTSXFileCommand, FileCommand)
    public:
        ImportTSXFileCommand(const Header&, const std::filesystem::path&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        const std::filesystem::path& filepath() const { return m_filepath; }
        
        //const Url&     url() const { return m_url; }

    protected:
        ImportTSXFileCommand(const ImportTSXFileCommand&, const Header&);
        virtual ~ImportTSXFileCommand();
        
    private:
    
        std::filesystem::path m_filepath;
        //Url    m_url;

        ImportTSXFileCommand(const ImportTSXFileCommand&) = delete;
        ImportTSXFileCommand(ImportTSXFileCommand&&) = delete;
        ImportTSXFileCommand& operator=(const ImportTSXFileCommand&) = delete;
        ImportTSXFileCommand& operator=(ImportTSXFileCommand&&) = delete;
    };
}
