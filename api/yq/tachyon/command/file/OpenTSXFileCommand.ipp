////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "OpenTSXFileCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::OpenTSXFileCommand)

namespace yq::tachyon {

    OpenTSXFileCommand::OpenTSXFileCommand(const Header&h, const std::filesystem::path& dm) : FileCommand(h), m_filepath(dm)
    {
    }

    OpenTSXFileCommand::OpenTSXFileCommand(const OpenTSXFileCommand& cp, const Header& h) : 
        FileCommand(cp, h), m_filepath(cp.m_filepath)
    {
    }
    
    OpenTSXFileCommand::~OpenTSXFileCommand()
    {
    }

    PostCPtr    OpenTSXFileCommand::clone(rebind_k, const Header&h) const 
    {
        return new OpenTSXFileCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void OpenTSXFileCommand::init_meta()
    {
        auto w = writer<OpenTSXFileCommand>();
        w.description("Open TSX File Command");
        //w.property("url", &OpenTSXFileCommand::m_url); 
    }
}
