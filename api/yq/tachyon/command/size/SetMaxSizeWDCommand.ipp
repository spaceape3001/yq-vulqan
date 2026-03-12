////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMaxSizeWDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMaxSizeʷDCommand)

namespace yq::tachyon {
    SetMaxSizeʷDCommand::SetMaxSizeʷDCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMaxSizeʷDCommand::SetMaxSizeʷDCommand(const Header& h, double v) : 
        SizeCommand(h), m_w(v)
    {
    }

    SetMaxSizeʷDCommand::SetMaxSizeʷDCommand(const SetMaxSizeʷDCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_w(cp.m_w)
    {
    }
    
    SetMaxSizeʷDCommand::~SetMaxSizeʷDCommand()
    {
    }

    PostCPtr    SetMaxSizeʷDCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMaxSizeʷDCommand(*this, h);
    }
    
    void SetMaxSizeʷDCommand::init_meta()
    {
        auto w = writer<SetMaxSizeʷDCommand>();
        w.description("SetMax Size DCommand in X");
        w.property("w", &SetMaxSizeʷDCommand::m_w).tag(kTag_Log).tag(kTag_Save);
    }
}
