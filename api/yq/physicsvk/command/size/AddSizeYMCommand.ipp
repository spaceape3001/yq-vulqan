////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddSizeYMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddSizeʸMCommand)

namespace yq::tachyon {
    AddSizeʸMCommand::AddSizeʸMCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    AddSizeʸMCommand::AddSizeʸMCommand(const Header& h, Meter y) : 
        SizeCommand(h), m_Δy(y)
    {
    }
    
    AddSizeʸMCommand::AddSizeʸMCommand(const AddSizeʸMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δy(cp.m_Δy)
    {
    }

    AddSizeʸMCommand::~AddSizeʸMCommand()
    {
    }

    PostCPtr    AddSizeʸMCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddSizeʸMCommand(*this, h);
    }
    
    void AddSizeʸMCommand::init_meta()
    {
        auto w = writer<AddSizeʸMCommand>();
        w.description("Add Size MCommand in Y");
        w.property("Δy", &AddSizeʸMCommand::m_Δy).tag(kTag_Log).tag(kTag_Save);
    }
}
