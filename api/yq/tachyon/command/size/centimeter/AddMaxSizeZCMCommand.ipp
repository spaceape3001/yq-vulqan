////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddMaxSizeZCMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddMaxSizeᶻCMCommand)

namespace yq::tachyon {
    AddMaxSizeᶻCMCommand::AddMaxSizeᶻCMCommand(const Header&h) : 
        SizeCommand(h)
    {
    }
    
    AddMaxSizeᶻCMCommand::AddMaxSizeᶻCMCommand(const Header&h, Centimeter z) : 
        SizeCommand(h), m_Δz(z)
    {
    }

    AddMaxSizeᶻCMCommand::AddMaxSizeᶻCMCommand(const AddMaxSizeᶻCMCommand& cp, const Header& h) : 
        SizeCommand(cp, h), m_Δz(cp.m_Δz)
    {
    }

    AddMaxSizeᶻCMCommand::~AddMaxSizeᶻCMCommand()
    {
    }

    PostCPtr    AddMaxSizeᶻCMCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddMaxSizeᶻCMCommand(*this, h);
    }
    
    void AddMaxSizeᶻCMCommand::init_meta()
    {
        auto w = writer<AddMaxSizeᶻCMCommand>();
        w.description("AddMax Size CMCommand in Z");
        w.property("Δz", &AddMaxSizeᶻCMCommand::m_Δz).tag(kTag_Log).tag(kTag_Save);
    }
}
