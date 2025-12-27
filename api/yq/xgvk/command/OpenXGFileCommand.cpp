////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "OpenXGFileCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::OpenXGFileCommand)

namespace yq::tachyon {

    OpenXGFileCommand::OpenXGFileCommand(const Header&h, const std::filesystem::path& v) : XGVkCommand(h), m_file(v)
    {
    }

    OpenXGFileCommand::OpenXGFileCommand(const OpenXGFileCommand& cp, const Header& h) : 
        XGVkCommand(cp, h), m_file(cp.m_file)
    {
    }
    
    OpenXGFileCommand::~OpenXGFileCommand()
    {
    }

    tachyon::PostCPtr    OpenXGFileCommand::clone(rebind_k, const Header&h) const 
    {
        return new OpenXGFileCommand(*this, h);
    }
    
    ////////////////////////////////////////////////////////////////////////////

    void OpenXGFileCommand::init_meta()
    {
        auto w = writer<OpenXGFileCommand>();
        w.description("XGVk Open File Command");
        //w.property("file", &OpenXGFileCommand::m_file);  // TODO (file as an any)
    }
}
