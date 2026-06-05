////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddPositionYCMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddPositionʸCMCommand)

namespace yq::tachyon {
    AddPositionʸCMCommand::AddPositionʸCMCommand(const Header&h) : 
        PositionCommand(h)
    {
    }

    AddPositionʸCMCommand::AddPositionʸCMCommand(const Header&h, Centimeter Δy) : 
        PositionCommand(h), m_Δy(Δy)
    {
    }

    AddPositionʸCMCommand::AddPositionʸCMCommand(const AddPositionʸCMCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δy(cp.m_Δy)
    {
    }
    
    AddPositionʸCMCommand::~AddPositionʸCMCommand()
    {
    }
    
    PostCPtr    AddPositionʸCMCommand::clone(rebind_k, const Header& h) const 
    {
        return new AddPositionʸCMCommand(*this, h);
    }

    void AddPositionʸCMCommand::init_meta()
    {
        auto w = writer<AddPositionʸCMCommand>();
        w.description("Add Position Command in Y (meters)");
        w.property("Δy", &AddPositionʸCMCommand::Δy).tag(kTag_Log).tag(kTag_Save);
    }
}
