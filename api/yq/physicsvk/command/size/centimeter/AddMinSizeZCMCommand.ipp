////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddMinSizeZCMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMinSizeᶻCMCommand)

namespace yq::tachyon {
    AddMinSizeᶻCMCommand::AddMinSizeᶻCMCommand(const Header&h) : 
        SizeCommand(h)
    {
    }
    
    AddMinSizeᶻCMCommand::AddMinSizeᶻCMCommand(const Header&h, Centimeter z) : 
        SizeCommand(h), m_Δz(z)
    {
    }

    AddMinSizeᶻCMCommand::AddMinSizeᶻCMCommand(const AddMinSizeᶻCMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δz(cp.m_Δz)
    {
    }

    AddMinSizeᶻCMCommand::~AddMinSizeᶻCMCommand()
    {
    }

    PostCPtr    AddMinSizeᶻCMCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMinSizeᶻCMCommand(*this, h);
    }
    
    void AddMinSizeᶻCMCommand::init_meta()
    {
        auto w = writer<AddMinSizeᶻCMCommand>();
        w.description("AddMin Size CMCommand in Z");
        w.property("Δz", &AddMinSizeᶻCMCommand::m_Δz).tag(kTag_Log).tag(kTag_Save);
    }
}
