////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMaxSizeYDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMaxSizeʸDCommand)

namespace yq::tachyon {
    SetMaxSizeʸDCommand::SetMaxSizeʸDCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMaxSizeʸDCommand::SetMaxSizeʸDCommand(const Header& h, double v) : 
        SizeCommand(h), m_y(v)
    {
    }

    SetMaxSizeʸDCommand::SetMaxSizeʸDCommand(const SetMaxSizeʸDCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_y(cp.m_y)
    {
    }
    
    SetMaxSizeʸDCommand::~SetMaxSizeʸDCommand()
    {
    }

    PostCPtr    SetMaxSizeʸDCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMaxSizeʸDCommand(*this, h);
    }
    
    void SetMaxSizeʸDCommand::init_meta()
    {
        auto w = writer<SetMaxSizeʸDCommand>();
        w.description("SetMax Size DCommand in Y");
        w.property("y", &SetMaxSizeʸDCommand::m_y).tag(kTag_Log).tag(kTag_Save);
    }
}
