////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddSizeZCMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddSizeᶻCMCommand)

namespace yq::tachyon {
    AddSizeᶻCMCommand::AddSizeᶻCMCommand(const Header&h) : 
        SizeCommand(h)
    {
    }
    
    AddSizeᶻCMCommand::AddSizeᶻCMCommand(const Header&h, Centimeter z) : 
        SizeCommand(h), m_Δz(z)
    {
    }

    AddSizeᶻCMCommand::AddSizeᶻCMCommand(const AddSizeᶻCMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δz(cp.m_Δz)
    {
    }

    AddSizeᶻCMCommand::~AddSizeᶻCMCommand()
    {
    }

    PostCPtr    AddSizeᶻCMCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddSizeᶻCMCommand(*this, h);
    }
    
    void AddSizeᶻCMCommand::init_meta()
    {
        auto w = writer<AddSizeᶻCMCommand>();
        w.description("Add Size CMCommand in Z");
        w.property("Δz", &AddSizeᶻCMCommand::m_Δz).tag(kTag_Log).tag(kTag_Save);
    }
}
