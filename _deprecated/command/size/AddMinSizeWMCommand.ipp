////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddMinSizeWMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMinSizeʷMCommand)

namespace yq::tachyon {
    AddMinSizeʷMCommand::AddMinSizeʷMCommand(const Header&h, Meter x) : 
        SizeCommand(h), m_Δw(x)
    {
    }

    AddMinSizeʷMCommand::AddMinSizeʷMCommand(const AddMinSizeʷMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δw(cp.m_Δw)
    {
    }
    
    AddMinSizeʷMCommand::~AddMinSizeʷMCommand()
    {
    }
    
    PostCPtr    AddMinSizeʷMCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMinSizeʷMCommand(*this, h);
    }

    void AddMinSizeʷMCommand::init_meta()
    {
        auto w = writer<AddMinSizeʷMCommand>();
        w.description("AddMin Size MCommand in X");
        w.property("Δw", &AddMinSizeʷMCommand::m_Δw).tag(kTag_Log).tag(kTag_Save);
    }
}
