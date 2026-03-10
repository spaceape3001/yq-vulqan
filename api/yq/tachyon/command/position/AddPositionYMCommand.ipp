////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddPositionYMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddPositionYMCommand)

namespace yq::tachyon {
    AddPositionYMCommand::AddPositionYMCommand(const Header&h) : 
        PositionCommand(h)
    {
    }

    AddPositionYMCommand::AddPositionYMCommand(const Header&h, Meter Δy) : 
        PositionCommand(h), m_Δy(Δy)
    {
    }

    AddPositionYMCommand::AddPositionYMCommand(const AddPositionYMCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δy(cp.m_Δy)
    {
    }
    
    AddPositionYMCommand::~AddPositionYMCommand()
    {
    }
    
    PostCPtr    AddPositionYMCommand::clone(rebind_k, const Header& h) const 
    {
        return new AddPositionYMCommand(*this, h);
    }

    void AddPositionYMCommand::init_meta()
    {
        auto w = writer<AddPositionYMCommand>();
        w.description("Add Position Command in Y (meters)");
        w.property("Δy", &AddPositionYMCommand::Δy).tag(kTag_Log).tag(kTag_Save);
    }
}
