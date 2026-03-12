////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddMaxSizeWMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMaxSizeʷMCommand)

namespace yq::tachyon {
    AddMaxSizeʷMCommand::AddMaxSizeʷMCommand(const Header&h, Meter x) : 
        SizeCommand(h), m_Δw(x)
    {
    }

    AddMaxSizeʷMCommand::AddMaxSizeʷMCommand(const AddMaxSizeʷMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δw(cp.m_Δw)
    {
    }
    
    AddMaxSizeʷMCommand::~AddMaxSizeʷMCommand()
    {
    }
    
    PostCPtr    AddMaxSizeʷMCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMaxSizeʷMCommand(*this, h);
    }

    void AddMaxSizeʷMCommand::init_meta()
    {
        auto w = writer<AddMaxSizeʷMCommand>();
        w.description("AddMax Size MCommand in X");
        w.property("Δw", &AddMaxSizeʷMCommand::m_Δw).tag(kTag_Log).tag(kTag_Save);
    }
}
