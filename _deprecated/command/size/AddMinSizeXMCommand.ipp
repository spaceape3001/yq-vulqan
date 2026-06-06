////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddMinSizeXMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMinSizeˣMCommand)

namespace yq::tachyon {
    AddMinSizeˣMCommand::AddMinSizeˣMCommand(const Header&h, Meter x) : 
        SizeCommand(h), m_Δx(x)
    {
    }

    AddMinSizeˣMCommand::AddMinSizeˣMCommand(const AddMinSizeˣMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δx(cp.m_Δx)
    {
    }
    
    AddMinSizeˣMCommand::~AddMinSizeˣMCommand()
    {
    }
    
    PostCPtr    AddMinSizeˣMCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMinSizeˣMCommand(*this, h);
    }

    void AddMinSizeˣMCommand::init_meta()
    {
        auto w = writer<AddMinSizeˣMCommand>();
        w.description("AddMin Size MCommand in X");
        w.property("Δx", &AddMinSizeˣMCommand::m_Δx).tag(kTag_Log).tag(kTag_Save);
    }
}
