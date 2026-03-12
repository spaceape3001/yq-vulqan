////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMinSizeYDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMinSizeʸDCommand)

namespace yq::tachyon {
    SetMinSizeʸDCommand::SetMinSizeʸDCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMinSizeʸDCommand::SetMinSizeʸDCommand(const Header& h, double v) : 
        SizeCommand(h), m_y(v)
    {
    }

    SetMinSizeʸDCommand::SetMinSizeʸDCommand(const SetMinSizeʸDCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_y(cp.m_y)
    {
    }
    
    SetMinSizeʸDCommand::~SetMinSizeʸDCommand()
    {
    }

    PostCPtr    SetMinSizeʸDCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMinSizeʸDCommand(*this, h);
    }
    
    void SetMinSizeʸDCommand::init_meta()
    {
        auto w = writer<SetMinSizeʸDCommand>();
        w.description("SetMin Size DCommand in Y");
        w.property("y", &SetMinSizeʸDCommand::m_y).tag(kTag_Log).tag(kTag_Save);
    }
}
