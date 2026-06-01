////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddSizeWMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddSizeʷMCommand)

namespace yq::tachyon {
    AddSizeʷMCommand::AddSizeʷMCommand(const Header&h, Meter x) : 
        SizeCommand(h), m_Δw(x)
    {
    }

    AddSizeʷMCommand::AddSizeʷMCommand(const AddSizeʷMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δw(cp.m_Δw)
    {
    }
    
    AddSizeʷMCommand::~AddSizeʷMCommand()
    {
    }
    
    PostCPtr    AddSizeʷMCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddSizeʷMCommand(*this, h);
    }

    void AddSizeʷMCommand::init_meta()
    {
        auto w = writer<AddSizeʷMCommand>();
        w.description("Add Size MCommand in X");
        w.property("Δw", &AddSizeʷMCommand::m_Δw).tag(kTag_Log).tag(kTag_Save);
    }
}
