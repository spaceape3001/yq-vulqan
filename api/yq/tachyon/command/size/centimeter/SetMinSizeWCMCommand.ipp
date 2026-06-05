////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMinSizeWCMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMinSizeʷCMCommand)

namespace yq::tachyon {
    SetMinSizeʷCMCommand::SetMinSizeʷCMCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMinSizeʷCMCommand::SetMinSizeʷCMCommand(const Header& h, Centimeter v) : 
        SizeCommand(h), m_w(v)
    {
    }

    SetMinSizeʷCMCommand::SetMinSizeʷCMCommand(const SetMinSizeʷCMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_w(cp.m_w)
    {
    }
    
    SetMinSizeʷCMCommand::~SetMinSizeʷCMCommand()
    {
    }

    PostCPtr    SetMinSizeʷCMCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMinSizeʷCMCommand(*this, h);
    }
    
    void SetMinSizeʷCMCommand::init_meta()
    {
        auto w = writer<SetMinSizeʷCMCommand>();
        w.description("SetMin Size CMCommand in X");
        w.property("w", &SetMinSizeʷCMCommand::m_w).tag(kTag_Log).tag(kTag_Save);
    }
}
