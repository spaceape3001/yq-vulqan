////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddMinSizeZMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMinSizeᶻMCommand)

namespace yq::tachyon {
    AddMinSizeᶻMCommand::AddMinSizeᶻMCommand(const Header&h) : 
        SizeCommand(h)
    {
    }
    
    AddMinSizeᶻMCommand::AddMinSizeᶻMCommand(const Header&h, Meter z) : 
        SizeCommand(h), m_Δz(z)
    {
    }

    AddMinSizeᶻMCommand::AddMinSizeᶻMCommand(const AddMinSizeᶻMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δz(cp.m_Δz)
    {
    }

    AddMinSizeᶻMCommand::~AddMinSizeᶻMCommand()
    {
    }

    PostCPtr    AddMinSizeᶻMCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMinSizeᶻMCommand(*this, h);
    }
    
    void AddMinSizeᶻMCommand::init_meta()
    {
        auto w = writer<AddMinSizeᶻMCommand>();
        w.description("AddMin Size MCommand in Z");
        w.property("Δz", &AddMinSizeᶻMCommand::m_Δz).tag(kTag_Log).tag(kTag_Save);
    }
}
