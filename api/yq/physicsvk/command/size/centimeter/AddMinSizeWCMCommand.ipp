////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddMinSizeWCMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMinSizeʷCMCommand)

namespace yq::tachyon {
    AddMinSizeʷCMCommand::AddMinSizeʷCMCommand(const Header&h, Centimeter x) : 
        SizeCommand(h), m_Δw(x)
    {
    }

    AddMinSizeʷCMCommand::AddMinSizeʷCMCommand(const AddMinSizeʷCMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δw(cp.m_Δw)
    {
    }
    
    AddMinSizeʷCMCommand::~AddMinSizeʷCMCommand()
    {
    }
    
    PostCPtr    AddMinSizeʷCMCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMinSizeʷCMCommand(*this, h);
    }

    void AddMinSizeʷCMCommand::init_meta()
    {
        auto w = writer<AddMinSizeʷCMCommand>();
        w.description("AddMin Size CMCommand in X");
        w.property("Δw", &AddMinSizeʷCMCommand::m_Δw).tag(kTag_Log).tag(kTag_Save);
    }
}
