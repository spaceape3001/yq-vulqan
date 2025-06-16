////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/size/AddSizeYCommand.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddSizeʸCommand)

namespace yq::tachyon {
    AddSizeʸCommand::AddSizeʸCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    AddSizeʸCommand::AddSizeʸCommand(const Header& h, double y) : 
        SizeCommand(h), m_Δy(y)
    {
    }
    
    AddSizeʸCommand::AddSizeʸCommand(const AddSizeʸCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δy(cp.m_Δy)
    {
    }

    AddSizeʸCommand::~AddSizeʸCommand()
    {
    }

    PostCPtr    AddSizeʸCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddSizeʸCommand(*this, h);
    }
    
    void AddSizeʸCommand::init_info()
    {
        auto w = writer<AddSizeʸCommand>();
        w.description("Add Size Command in Y");
        w.property("Δy", &AddSizeʸCommand::m_Δy).tag(kTag_Log).tag(kTag_Save);
    }
}
