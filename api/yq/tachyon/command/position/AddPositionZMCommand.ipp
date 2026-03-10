////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddPositionZMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddPositionᶻMCommand)

namespace yq::tachyon {
    AddPositionᶻMCommand::AddPositionᶻMCommand(const Header&h) : 
        PositionCommand(h)
    {
    }
    
    AddPositionᶻMCommand::AddPositionᶻMCommand(const Header&h, Meter Δz) : 
        PositionCommand(h), m_Δz(Δz)
    {
    }

    AddPositionᶻMCommand::AddPositionᶻMCommand(const AddPositionᶻMCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δz(cp.m_Δz)
    {
    }

    AddPositionᶻMCommand::~AddPositionᶻMCommand()
    {
    }
    
    PostCPtr    AddPositionᶻMCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddPositionᶻMCommand(*this, h);
    }

    void AddPositionᶻMCommand::init_meta()
    {
        auto w = writer<AddPositionᶻMCommand>();
        w.description("Add Position Command in Z (meters)");
        w.property("Δz", &AddPositionᶻMCommand::Δz).tag(kTag_Log).tag(kTag_Save);
    }
}
