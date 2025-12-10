////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMaxSizeWCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMaxSizeʷCommand)

namespace yq::tachyon {
    SetMaxSizeʷCommand::SetMaxSizeʷCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMaxSizeʷCommand::SetMaxSizeʷCommand(const Header& h, double v) : 
        SizeCommand(h), m_w(v)
    {
    }

    SetMaxSizeʷCommand::SetMaxSizeʷCommand(const SetMaxSizeʷCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_w(cp.m_w)
    {
    }
    
    SetMaxSizeʷCommand::~SetMaxSizeʷCommand()
    {
    }

    PostCPtr    SetMaxSizeʷCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMaxSizeʷCommand(*this, h);
    }
    
    void SetMaxSizeʷCommand::init_meta()
    {
        auto w = writer<SetMaxSizeʷCommand>();
        w.description("SetMax Size Command in X");
        w.property("w", &SetMaxSizeʷCommand::m_w).tag(kTag_Log).tag(kTag_Save);
    }
}
