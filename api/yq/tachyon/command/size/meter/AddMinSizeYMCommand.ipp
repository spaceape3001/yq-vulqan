////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddMinSizeYMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMinSizeʸMCommand)

namespace yq::tachyon {
    AddMinSizeʸMCommand::AddMinSizeʸMCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    AddMinSizeʸMCommand::AddMinSizeʸMCommand(const Header& h, Meter y) : 
        SizeCommand(h), m_Δy(y)
    {
    }
    
    AddMinSizeʸMCommand::AddMinSizeʸMCommand(const AddMinSizeʸMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δy(cp.m_Δy)
    {
    }

    AddMinSizeʸMCommand::~AddMinSizeʸMCommand()
    {
    }

    PostCPtr    AddMinSizeʸMCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMinSizeʸMCommand(*this, h);
    }
    
    void AddMinSizeʸMCommand::init_meta()
    {
        auto w = writer<AddMinSizeʸMCommand>();
        w.description("AddMin Size MCommand in Y");
        w.property("Δy", &AddMinSizeʸMCommand::m_Δy).tag(kTag_Log).tag(kTag_Save);
    }
}
