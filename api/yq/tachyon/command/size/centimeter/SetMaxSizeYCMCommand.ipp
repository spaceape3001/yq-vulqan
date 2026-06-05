////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMaxSizeYCMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMaxSizeʸCMCommand)

namespace yq::tachyon {
    SetMaxSizeʸCMCommand::SetMaxSizeʸCMCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMaxSizeʸCMCommand::SetMaxSizeʸCMCommand(const Header& h, Centimeter v) : 
        SizeCommand(h), m_y(v)
    {
    }

    SetMaxSizeʸCMCommand::SetMaxSizeʸCMCommand(const SetMaxSizeʸCMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_y(cp.m_y)
    {
    }
    
    SetMaxSizeʸCMCommand::~SetMaxSizeʸCMCommand()
    {
    }

    PostCPtr    SetMaxSizeʸCMCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMaxSizeʸCMCommand(*this, h);
    }
    
    void SetMaxSizeʸCMCommand::init_meta()
    {
        auto w = writer<SetMaxSizeʸCMCommand>();
        w.description("SetMax Size CMCommand in Y");
        w.property("y", &SetMaxSizeʸCMCommand::m_y).tag(kTag_Log).tag(kTag_Save);
    }
}
