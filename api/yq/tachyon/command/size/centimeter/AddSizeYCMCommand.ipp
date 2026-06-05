////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddSizeYCMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddSizeʸCMCommand)

namespace yq::tachyon {
    AddSizeʸCMCommand::AddSizeʸCMCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    AddSizeʸCMCommand::AddSizeʸCMCommand(const Header& h, Centimeter y) : 
        SizeCommand(h), m_Δy(y)
    {
    }
    
    AddSizeʸCMCommand::AddSizeʸCMCommand(const AddSizeʸCMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δy(cp.m_Δy)
    {
    }

    AddSizeʸCMCommand::~AddSizeʸCMCommand()
    {
    }

    PostCPtr    AddSizeʸCMCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddSizeʸCMCommand(*this, h);
    }
    
    void AddSizeʸCMCommand::init_meta()
    {
        auto w = writer<AddSizeʸCMCommand>();
        w.description("Add Size CMCommand in Y");
        w.property("Δy", &AddSizeʸCMCommand::m_Δy).tag(kTag_Log).tag(kTag_Save);
    }
}
