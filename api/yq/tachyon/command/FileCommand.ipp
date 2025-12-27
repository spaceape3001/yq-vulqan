////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "FileCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::FileCommand)

namespace yq::tachyon {

    FileCommand::FileCommand(const Header&h) : SpatialCommand(h)
    {
    }

    FileCommand::FileCommand(const FileCommand& cp, const Header& h) : SpatialCommand(cp, h)
    {
    }
    
    FileCommand::~FileCommand()
    {
    }

    PostCPtr    FileCommand::clone(rebind_k, const Header&h) const 
    {
        return new FileCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void FileCommand::init_meta()
    {
        auto w = writer<FileCommand>();
        w.description("File Command");
    }
}
