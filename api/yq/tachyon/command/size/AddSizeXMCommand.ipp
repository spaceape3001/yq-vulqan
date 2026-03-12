////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddSizeXMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddSizeˣMCommand)

namespace yq::tachyon {
    AddSizeˣMCommand::AddSizeˣMCommand(const Header&h, Meter x) : 
        SizeCommand(h), m_Δx(x)
    {
    }

    AddSizeˣMCommand::AddSizeˣMCommand(const AddSizeˣMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δx(cp.m_Δx)
    {
    }
    
    AddSizeˣMCommand::~AddSizeˣMCommand()
    {
    }
    
    PostCPtr    AddSizeˣMCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddSizeˣMCommand(*this, h);
    }

    void AddSizeˣMCommand::init_meta()
    {
        auto w = writer<AddSizeˣMCommand>();
        w.description("Add Size MCommand in X");
        w.property("Δx", &AddSizeˣMCommand::m_Δx).tag(kTag_Log).tag(kTag_Save);
    }
}
