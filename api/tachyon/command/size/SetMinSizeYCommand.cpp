////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/SetMinSizeYCommand.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SetMinSizeʸCommand)

namespace yq::tachyon {
    SetMinSizeʸCommand::SetMinSizeʸCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    SetMinSizeʸCommand::SetMinSizeʸCommand(const Header& h, double v) : 
        SizeCommand(h), m_y(v)
    {
    }

    SetMinSizeʸCommand::SetMinSizeʸCommand(const SetMinSizeʸCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_y(cp.m_y)
    {
    }
    
    SetMinSizeʸCommand::~SetMinSizeʸCommand()
    {
    }

    PostCPtr    SetMinSizeʸCommand::clone(rebind_k, const Header&h) const 
    {
        return new SetMinSizeʸCommand(*this, h);
    }
    
    void SetMinSizeʸCommand::init_info()
    {
        auto w = writer<SetMinSizeʸCommand>();
        w.description("SetMin Size Command in Y");
        w.property("y", &SetMinSizeʸCommand::m_y).tag(kTag_Log).tag(kTag_Save);
    }
}
