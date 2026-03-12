////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetSizeYDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetSizeʸDCommand)

namespace yq::tachyon {
    SetSizeʸDCommand::SetSizeʸDCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetSizeʸDCommand::SetSizeʸDCommand(const Header& h, double v) : 
        SizeCommand(h), m_y(v)
    {
    }

    SetSizeʸDCommand::SetSizeʸDCommand(const SetSizeʸDCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_y(cp.m_y)
    {
    }
    
    SetSizeʸDCommand::~SetSizeʸDCommand()
    {
    }

    PostCPtr    SetSizeʸDCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetSizeʸDCommand(*this, h);
    }
    
    void SetSizeʸDCommand::init_meta()
    {
        auto w = writer<SetSizeʸDCommand>();
        w.description("Set Size DCommand in Y");
        w.property("y", &SetSizeʸDCommand::m_y).tag(kTag_Log).tag(kTag_Save);
    }
}
