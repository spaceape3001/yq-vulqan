////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddPositionZMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddPositionZMCommand)

namespace yq::tachyon {
    AddPositionZMCommand::AddPositionZMCommand(const Header&h) : 
        PositionCommand(h)
    {
    }
    
    AddPositionZMCommand::AddPositionZMCommand(const Header&h, Meter Δz) : 
        PositionCommand(h), m_Δz(Δz)
    {
    }

    AddPositionZMCommand::AddPositionZMCommand(const AddPositionZMCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δz(cp.m_Δz)
    {
    }

    AddPositionZMCommand::~AddPositionZMCommand()
    {
    }
    
    PostCPtr    AddPositionZMCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddPositionZMCommand(*this, h);
    }

    void AddPositionZMCommand::init_meta()
    {
        auto w = writer<AddPositionZMCommand>();
        w.description("Add Position Command in Z (meters)");
        w.property("Δz", &AddPositionZMCommand::Δz).tag(kTag_Log).tag(kTag_Save);
    }
}
