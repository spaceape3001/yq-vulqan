////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "XGCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::XGCommand)

namespace yq::tachyon {
    XGCommand::XGCommand(const Header& h) : Command(h)
    {
    }
    
    XGCommand::XGCommand(const XGCommand&cp, const Header&h) : Command(cp, h)
    {
    }

    XGCommand::~XGCommand()
    {
    }
    
    void XGCommand::init_meta()
    {
        auto w = writer<XGCommand>();
        w.abstract();
        w.description("XGVk Command");
    }
}
