////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMaxSizeWMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMaxSizeʷMCommand)

namespace yq::tachyon {
    SetMaxSizeʷMCommand::SetMaxSizeʷMCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMaxSizeʷMCommand::SetMaxSizeʷMCommand(const Header& h, Meter v) : 
        SizeCommand(h), m_w(v)
    {
    }

    SetMaxSizeʷMCommand::SetMaxSizeʷMCommand(const SetMaxSizeʷMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_w(cp.m_w)
    {
    }
    
    SetMaxSizeʷMCommand::~SetMaxSizeʷMCommand()
    {
    }

    PostCPtr    SetMaxSizeʷMCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMaxSizeʷMCommand(*this, h);
    }
    
    void SetMaxSizeʷMCommand::init_meta()
    {
        auto w = writer<SetMaxSizeʷMCommand>();
        w.description("SetMax Size MCommand in X");
        w.property("w", &SetMaxSizeʷMCommand::m_w).tag(kTag_Log).tag(kTag_Save);
    }
}
