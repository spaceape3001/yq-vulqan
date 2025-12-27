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
    class OpenTSXFileCommand : public FileCommand {
        YQ_OBJECT_DECLARE(OpenTSXFileCommand, FileCommand)
    public:
        OpenTSXFileCommand(const Header&, const std::filesystem::path&);
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

        static void init_meta();
        
        const std::filesystem::path& filepath() const { return m_filepath; }
        
        //const Url&     url() const { return m_url; }

    protected:
        OpenTSXFileCommand(const OpenTSXFileCommand&, const Header&);
        virtual ~OpenTSXFileCommand();
        
    private:
    
        std::filesystem::path m_filepath;
        //Url    m_url;

        OpenTSXFileCommand(const OpenTSXFileCommand&) = delete;
        OpenTSXFileCommand(OpenTSXFileCommand&&) = delete;
        OpenTSXFileCommand& operator=(const OpenTSXFileCommand&) = delete;
        OpenTSXFileCommand& operator=(OpenTSXFileCommand&&) = delete;
    };
}
