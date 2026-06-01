////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddMaxSizeYMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMaxSizeʸMCommand)

namespace yq::tachyon {
    AddMaxSizeʸMCommand::AddMaxSizeʸMCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    AddMaxSizeʸMCommand::AddMaxSizeʸMCommand(const Header& h, Meter y) : 
        SizeCommand(h), m_Δy(y)
    {
    }
    
    AddMaxSizeʸMCommand::AddMaxSizeʸMCommand(const AddMaxSizeʸMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δy(cp.m_Δy)
    {
    }

    AddMaxSizeʸMCommand::~AddMaxSizeʸMCommand()
    {
    }

    PostCPtr    AddMaxSizeʸMCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMaxSizeʸMCommand(*this, h);
    }
    
    void AddMaxSizeʸMCommand::init_meta()
    {
        auto w = writer<AddMaxSizeʸMCommand>();
        w.description("AddMax Size MCommand in Y");
        w.property("Δy", &AddMaxSizeʸMCommand::m_Δy).tag(kTag_Log).tag(kTag_Save);
    }
}
