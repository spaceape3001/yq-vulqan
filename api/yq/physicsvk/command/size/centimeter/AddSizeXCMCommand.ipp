////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddSizeXCMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddSizeˣCMCommand)

namespace yq::tachyon {
    AddSizeˣCMCommand::AddSizeˣCMCommand(const Header&h, Centimeter x) : 
        SizeCommand(h), m_Δx(x)
    {
    }

    AddSizeˣCMCommand::AddSizeˣCMCommand(const AddSizeˣCMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δx(cp.m_Δx)
    {
    }
    
    AddSizeˣCMCommand::~AddSizeˣCMCommand()
    {
    }
    
    PostCPtr    AddSizeˣCMCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddSizeˣCMCommand(*this, h);
    }

    void AddSizeˣCMCommand::init_meta()
    {
        auto w = writer<AddSizeˣCMCommand>();
        w.description("Add Size CMCommand in X");
        w.property("Δx", &AddSizeˣCMCommand::m_Δx).tag(kTag_Log).tag(kTag_Save);
    }
}
