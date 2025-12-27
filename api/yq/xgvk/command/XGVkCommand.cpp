////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "XGVkCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::XGVkCommand)

namespace yq::tachyon {
    XGVkCommand::XGVkCommand(const Header& h) : Command(h)
    {
    }
    
    XGVkCommand::XGVkCommand(const XGVkCommand&cp, const Header&h) : Command(cp, h)
    {
    }

    XGVkCommand::~XGVkCommand()
    {
    }
    
    void XGVkCommand::init_meta()
    {
        auto w = writer<XGVkCommand>();
        w.abstract();
        w.description("XGVk Command");
    }
}
