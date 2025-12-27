////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ImportTSXFileCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ImportTSXFileCommand)

namespace yq::tachyon {

    ImportTSXFileCommand::ImportTSXFileCommand(const Header&h, const std::filesystem::path& dm) : FileCommand(h), m_filepath(dm)
    {
    }

    ImportTSXFileCommand::ImportTSXFileCommand(const ImportTSXFileCommand& cp, const Header& h) : 
        FileCommand(cp, h), m_filepath(cp.m_filepath)
    {
    }
    
    ImportTSXFileCommand::~ImportTSXFileCommand()
    {
    }

    PostCPtr    ImportTSXFileCommand::clone(rebind_k, const Header&h) const 
    {
        return new ImportTSXFileCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void ImportTSXFileCommand::init_meta()
    {
        auto w = writer<ImportTSXFileCommand>();
        w.description("Open TSX File Command");
        //w.property("url", &ImportTSXFileCommand::m_url); 
    }
}
