////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddMaxSizeXCMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMaxSizeˣCMCommand)

namespace yq::tachyon {
    AddMaxSizeˣCMCommand::AddMaxSizeˣCMCommand(const Header&h, Centimeter x) : 
        SizeCommand(h), m_Δx(x)
    {
    }

    AddMaxSizeˣCMCommand::AddMaxSizeˣCMCommand(const AddMaxSizeˣCMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δx(cp.m_Δx)
    {
    }
    
    AddMaxSizeˣCMCommand::~AddMaxSizeˣCMCommand()
    {
    }
    
    PostCPtr    AddMaxSizeˣCMCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMaxSizeˣCMCommand(*this, h);
    }

    void AddMaxSizeˣCMCommand::init_meta()
    {
        auto w = writer<AddMaxSizeˣCMCommand>();
        w.description("AddMax Size CMCommand in X");
        w.property("Δx", &AddMaxSizeˣCMCommand::m_Δx).tag(kTag_Log).tag(kTag_Save);
    }
}
