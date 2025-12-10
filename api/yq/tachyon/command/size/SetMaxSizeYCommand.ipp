////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMaxSizeYCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMaxSizeʸCommand)

namespace yq::tachyon {
    SetMaxSizeʸCommand::SetMaxSizeʸCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMaxSizeʸCommand::SetMaxSizeʸCommand(const Header& h, double v) : 
        SizeCommand(h), m_y(v)
    {
    }

    SetMaxSizeʸCommand::SetMaxSizeʸCommand(const SetMaxSizeʸCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_y(cp.m_y)
    {
    }
    
    SetMaxSizeʸCommand::~SetMaxSizeʸCommand()
    {
    }

    PostCPtr    SetMaxSizeʸCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMaxSizeʸCommand(*this, h);
    }
    
    void SetMaxSizeʸCommand::init_meta()
    {
        auto w = writer<SetMaxSizeʸCommand>();
        w.description("SetMax Size Command in Y");
        w.property("y", &SetMaxSizeʸCommand::m_y).tag(kTag_Log).tag(kTag_Save);
    }
}
