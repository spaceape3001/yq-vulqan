////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddMaxSizeYCMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMaxSizeʸCMCommand)

namespace yq::tachyon {
    AddMaxSizeʸCMCommand::AddMaxSizeʸCMCommand(const Header& h) : 
        SizeCommand(h)
    {
    }

    AddMaxSizeʸCMCommand::AddMaxSizeʸCMCommand(const Header& h, Centimeter y) : 
        SizeCommand(h), m_Δy(y)
    {
    }
    
    AddMaxSizeʸCMCommand::AddMaxSizeʸCMCommand(const AddMaxSizeʸCMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δy(cp.m_Δy)
    {
    }

    AddMaxSizeʸCMCommand::~AddMaxSizeʸCMCommand()
    {
    }

    PostCPtr    AddMaxSizeʸCMCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMaxSizeʸCMCommand(*this, h);
    }
    
    void AddMaxSizeʸCMCommand::init_meta()
    {
        auto w = writer<AddMaxSizeʸCMCommand>();
        w.description("AddMax Size CMCommand in Y");
        w.property("Δy", &AddMaxSizeʸCMCommand::m_Δy).tag(kTag_Log).tag(kTag_Save);
    }
}
