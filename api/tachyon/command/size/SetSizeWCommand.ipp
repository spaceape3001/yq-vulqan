////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/SetSizeWCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetSizeʷCommand)

namespace yq::tachyon {
    SetSizeʷCommand::SetSizeʷCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetSizeʷCommand::SetSizeʷCommand(const Header& h, double v) : 
        SizeCommand(h), m_w(v)
    {
    }

    SetSizeʷCommand::SetSizeʷCommand(const SetSizeʷCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_w(cp.m_w)
    {
    }
    
    SetSizeʷCommand::~SetSizeʷCommand()
    {
    }

    PostCPtr    SetSizeʷCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetSizeʷCommand(*this, h);
    }
    
    void SetSizeʷCommand::init_info()
    {
        auto w = writer<SetSizeʷCommand>();
        w.description("Set Size Command in X");
        w.property("w", &SetSizeʷCommand::m_w).tag(kTag_Log).tag(kTag_Save);
    }
}
