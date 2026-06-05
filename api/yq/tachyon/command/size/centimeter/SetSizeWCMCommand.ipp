////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetSizeWCMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetSizeʷCMCommand)

namespace yq::tachyon {
    SetSizeʷCMCommand::SetSizeʷCMCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetSizeʷCMCommand::SetSizeʷCMCommand(const Header& h, Centimeter v) : 
        SizeCommand(h), m_w(v)
    {
    }

    SetSizeʷCMCommand::SetSizeʷCMCommand(const SetSizeʷCMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_w(cp.m_w)
    {
    }
    
    SetSizeʷCMCommand::~SetSizeʷCMCommand()
    {
    }

    PostCPtr    SetSizeʷCMCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetSizeʷCMCommand(*this, h);
    }
    
    void SetSizeʷCMCommand::init_meta()
    {
        auto w = writer<SetSizeʷCMCommand>();
        w.description("Set Size CMCommand in X");
        w.property("w", &SetSizeʷCMCommand::m_w).tag(kTag_Log).tag(kTag_Save);
    }
}
