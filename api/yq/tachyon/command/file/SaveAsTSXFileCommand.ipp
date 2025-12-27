////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SaveAsTSXFileCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SaveAsTSXFileCommand)

namespace yq::tachyon {

    SaveAsTSXFileCommand::SaveAsTSXFileCommand(const Header&h, const std::filesystem::path& dm) : FileCommand(h), m_filepath(dm)
    {
    }

    SaveAsTSXFileCommand::SaveAsTSXFileCommand(const SaveAsTSXFileCommand& cp, const Header& h) : 
        FileCommand(cp, h), m_filepath(cp.m_filepath)
    {
    }
    
    SaveAsTSXFileCommand::~SaveAsTSXFileCommand()
    {
    }

    PostCPtr    SaveAsTSXFileCommand::clone(rebind_k, const Header&h) const 
    {
        return new SaveAsTSXFileCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void SaveAsTSXFileCommand::init_meta()
    {
        auto w = writer<SaveAsTSXFileCommand>();
        w.description("SaveAs TSX File Command");
        //w.property("url", &SaveAsTSXFileCommand::m_url); 
    }
}
