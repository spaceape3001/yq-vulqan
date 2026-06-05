////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddSizeWCMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddSizeʷCMCommand)

namespace yq::tachyon {
    AddSizeʷCMCommand::AddSizeʷCMCommand(const Header&h, Centimeter x) : 
        SizeCommand(h), m_Δw(x)
    {
    }

    AddSizeʷCMCommand::AddSizeʷCMCommand(const AddSizeʷCMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δw(cp.m_Δw)
    {
    }
    
    AddSizeʷCMCommand::~AddSizeʷCMCommand()
    {
    }
    
    PostCPtr    AddSizeʷCMCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddSizeʷCMCommand(*this, h);
    }

    void AddSizeʷCMCommand::init_meta()
    {
        auto w = writer<AddSizeʷCMCommand>();
        w.description("Add Size CMCommand in X");
        w.property("Δw", &AddSizeʷCMCommand::m_Δw).tag(kTag_Log).tag(kTag_Save);
    }
}
