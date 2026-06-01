////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SetMinSizeWMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMinSizeʷMCommand)

namespace yq::tachyon {
    SetMinSizeʷMCommand::SetMinSizeʷMCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMinSizeʷMCommand::SetMinSizeʷMCommand(const Header& h, Meter v) : 
        SizeCommand(h), m_w(v)
    {
    }

    SetMinSizeʷMCommand::SetMinSizeʷMCommand(const SetMinSizeʷMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_w(cp.m_w)
    {
    }
    
    SetMinSizeʷMCommand::~SetMinSizeʷMCommand()
    {
    }

    PostCPtr    SetMinSizeʷMCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMinSizeʷMCommand(*this, h);
    }
    
    void SetMinSizeʷMCommand::init_meta()
    {
        auto w = writer<SetMinSizeʷMCommand>();
        w.description("SetMin Size MCommand in X");
        w.property("w", &SetMinSizeʷMCommand::m_w).tag(kTag_Log).tag(kTag_Save);
    }
}
