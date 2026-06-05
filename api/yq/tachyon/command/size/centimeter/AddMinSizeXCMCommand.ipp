////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddMinSizeXCMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMinSizeˣCMCommand)

namespace yq::tachyon {
    AddMinSizeˣCMCommand::AddMinSizeˣCMCommand(const Header&h, Centimeter x) : 
        SizeCommand(h), m_Δx(x)
    {
    }

    AddMinSizeˣCMCommand::AddMinSizeˣCMCommand(const AddMinSizeˣCMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δx(cp.m_Δx)
    {
    }
    
    AddMinSizeˣCMCommand::~AddMinSizeˣCMCommand()
    {
    }
    
    PostCPtr    AddMinSizeˣCMCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMinSizeˣCMCommand(*this, h);
    }

    void AddMinSizeˣCMCommand::init_meta()
    {
        auto w = writer<AddMinSizeˣCMCommand>();
        w.description("AddMin Size CMCommand in X");
        w.property("Δx", &AddMinSizeˣCMCommand::m_Δx).tag(kTag_Log).tag(kTag_Save);
    }
}
