////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddPositionYMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddPositionʸMCommand)

namespace yq::tachyon {
    AddPositionʸMCommand::AddPositionʸMCommand(const Header&h) : 
        PositionCommand(h)
    {
    }

    AddPositionʸMCommand::AddPositionʸMCommand(const Header&h, Meter Δy) : 
        PositionCommand(h), m_Δy(Δy)
    {
    }

    AddPositionʸMCommand::AddPositionʸMCommand(const AddPositionʸMCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δy(cp.m_Δy)
    {
    }
    
    AddPositionʸMCommand::~AddPositionʸMCommand()
    {
    }
    
    PostCPtr    AddPositionʸMCommand::clone(rebind_k, const Header& h) const 
    {
        return new AddPositionʸMCommand(*this, h);
    }

    void AddPositionʸMCommand::init_meta()
    {
        auto w = writer<AddPositionʸMCommand>();
        w.description("Add Position Command in Y (meters)");
        w.property("Δy", &AddPositionʸMCommand::Δy).tag(kTag_Log).tag(kTag_Save);
    }
}
