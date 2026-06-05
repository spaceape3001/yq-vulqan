////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMaxSizeWCMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMaxSizeʷCMCommand)

namespace yq::tachyon {
    SetMaxSizeʷCMCommand::SetMaxSizeʷCMCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMaxSizeʷCMCommand::SetMaxSizeʷCMCommand(const Header& h, Centimeter v) : 
        SizeCommand(h), m_w(v)
    {
    }

    SetMaxSizeʷCMCommand::SetMaxSizeʷCMCommand(const SetMaxSizeʷCMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_w(cp.m_w)
    {
    }
    
    SetMaxSizeʷCMCommand::~SetMaxSizeʷCMCommand()
    {
    }

    PostCPtr    SetMaxSizeʷCMCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMaxSizeʷCMCommand(*this, h);
    }
    
    void SetMaxSizeʷCMCommand::init_meta()
    {
        auto w = writer<SetMaxSizeʷCMCommand>();
        w.description("SetMax Size CMCommand in X");
        w.property("w", &SetMaxSizeʷCMCommand::m_w).tag(kTag_Log).tag(kTag_Save);
    }
}
