////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SaveXGFileCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SaveXGFileCommand)

namespace yq::tachyon {

    SaveXGFileCommand::SaveXGFileCommand(const Header&h, const std::filesystem::path& v) : XGVkCommand(h), m_file(v)
    {
    }

    SaveXGFileCommand::SaveXGFileCommand(const SaveXGFileCommand& cp, const Header& h) : 
        XGVkCommand(cp, h), m_file(cp.m_file)
    {
    }
    
    SaveXGFileCommand::~SaveXGFileCommand()
    {
    }

    tachyon::PostCPtr    SaveXGFileCommand::clone(rebind_k, const Header&h) const 
    {
        return new SaveXGFileCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void SaveXGFileCommand::init_meta()
    {
        auto w = writer<SaveXGFileCommand>();
        w.description("XGVk Save File Command");
        //w.property("file", &SaveXGFileCommand::m_file);  // TODO (file as an any)
    }
}
