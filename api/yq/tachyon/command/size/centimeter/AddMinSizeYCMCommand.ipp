////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddMinSizeYCMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMinSizeʸCMCommand)

namespace yq::tachyon {
    AddMinSizeʸCMCommand::AddMinSizeʸCMCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    AddMinSizeʸCMCommand::AddMinSizeʸCMCommand(const Header& h, Centimeter y) : 
        SizeCommand(h), m_Δy(y)
    {
    }
    
    AddMinSizeʸCMCommand::AddMinSizeʸCMCommand(const AddMinSizeʸCMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δy(cp.m_Δy)
    {
    }

    AddMinSizeʸCMCommand::~AddMinSizeʸCMCommand()
    {
    }

    PostCPtr    AddMinSizeʸCMCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMinSizeʸCMCommand(*this, h);
    }
    
    void AddMinSizeʸCMCommand::init_meta()
    {
        auto w = writer<AddMinSizeʸCMCommand>();
        w.description("AddMin Size CMCommand in Y");
        w.property("Δy", &AddMinSizeʸCMCommand::m_Δy).tag(kTag_Log).tag(kTag_Save);
    }
}
