////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddMaxSizeWCMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMaxSizeʷCMCommand)

namespace yq::tachyon {
    AddMaxSizeʷCMCommand::AddMaxSizeʷCMCommand(const Header&h, Centimeter x) : 
        SizeCommand(h), m_Δw(x)
    {
    }

    AddMaxSizeʷCMCommand::AddMaxSizeʷCMCommand(const AddMaxSizeʷCMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δw(cp.m_Δw)
    {
    }
    
    AddMaxSizeʷCMCommand::~AddMaxSizeʷCMCommand()
    {
    }
    
    PostCPtr    AddMaxSizeʷCMCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMaxSizeʷCMCommand(*this, h);
    }

    void AddMaxSizeʷCMCommand::init_meta()
    {
        auto w = writer<AddMaxSizeʷCMCommand>();
        w.description("AddMax Size CMCommand in X");
        w.property("Δw", &AddMaxSizeʷCMCommand::m_Δw).tag(kTag_Log).tag(kTag_Save);
    }
}
