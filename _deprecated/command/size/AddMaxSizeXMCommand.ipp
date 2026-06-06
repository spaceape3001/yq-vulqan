////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddMaxSizeXMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMaxSizeˣMCommand)

namespace yq::tachyon {
    AddMaxSizeˣMCommand::AddMaxSizeˣMCommand(const Header&h, Meter x) : 
        SizeCommand(h), m_Δx(x)
    {
    }

    AddMaxSizeˣMCommand::AddMaxSizeˣMCommand(const AddMaxSizeˣMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δx(cp.m_Δx)
    {
    }
    
    AddMaxSizeˣMCommand::~AddMaxSizeˣMCommand()
    {
    }
    
    PostCPtr    AddMaxSizeˣMCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMaxSizeˣMCommand(*this, h);
    }

    void AddMaxSizeˣMCommand::init_meta()
    {
        auto w = writer<AddMaxSizeˣMCommand>();
        w.description("AddMax Size MCommand in X");
        w.property("Δx", &AddMaxSizeˣMCommand::m_Δx).tag(kTag_Log).tag(kTag_Save);
    }
}
