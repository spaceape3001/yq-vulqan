////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetSizeWDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetSizeʷDCommand)

namespace yq::tachyon {
    SetSizeʷDCommand::SetSizeʷDCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetSizeʷDCommand::SetSizeʷDCommand(const Header& h, double v) : 
        SizeCommand(h), m_w(v)
    {
    }

    SetSizeʷDCommand::SetSizeʷDCommand(const SetSizeʷDCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_w(cp.m_w)
    {
    }
    
    SetSizeʷDCommand::~SetSizeʷDCommand()
    {
    }

    PostCPtr    SetSizeʷDCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetSizeʷDCommand(*this, h);
    }
    
    void SetSizeʷDCommand::init_meta()
    {
        auto w = writer<SetSizeʷDCommand>();
        w.description("Set Size DCommand in X");
        w.property("w", &SetSizeʷDCommand::m_w).tag(kTag_Log).tag(kTag_Save);
    }
}
