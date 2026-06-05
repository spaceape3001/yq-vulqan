////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddPositionZCMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddPositionᶻCMCommand)

namespace yq::tachyon {
    AddPositionᶻCMCommand::AddPositionᶻCMCommand(const Header&h) : 
        PositionCommand(h)
    {
    }
    
    AddPositionᶻCMCommand::AddPositionᶻCMCommand(const Header&h, Centimeter Δz) : 
        PositionCommand(h), m_Δz(Δz)
    {
    }

    AddPositionᶻCMCommand::AddPositionᶻCMCommand(const AddPositionᶻCMCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δz(cp.m_Δz)
    {
    }

    AddPositionᶻCMCommand::~AddPositionᶻCMCommand()
    {
    }
    
    PostCPtr    AddPositionᶻCMCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddPositionᶻCMCommand(*this, h);
    }

    void AddPositionᶻCMCommand::init_meta()
    {
        auto w = writer<AddPositionᶻCMCommand>();
        w.description("Add Position Command in Z (meters)");
        w.property("Δz", &AddPositionᶻCMCommand::Δz).tag(kTag_Log).tag(kTag_Save);
    }
}
