////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/SetSizeYCommand.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetSizeʸCommand)

namespace yq::tachyon {
    SetSizeʸCommand::SetSizeʸCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetSizeʸCommand::SetSizeʸCommand(const Header& h, double v) : 
        SizeCommand(h), m_y(v)
    {
    }

    SetSizeʸCommand::SetSizeʸCommand(const SetSizeʸCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_y(cp.m_y)
    {
    }
    
    SetSizeʸCommand::~SetSizeʸCommand()
    {
    }

    PostCPtr    SetSizeʸCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetSizeʸCommand(*this, h);
    }
    
    void SetSizeʸCommand::init_info()
    {
        auto w = writer<SetSizeʸCommand>();
        w.description("Set Size Command in Y");
        w.property("y", &SetSizeʸCommand::m_y).tag(kTag_Log).tag(kTag_Save);
    }
}
