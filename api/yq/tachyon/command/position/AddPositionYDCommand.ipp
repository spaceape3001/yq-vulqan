////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddPositionYDCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddPositionʸDCommand)

namespace yq::tachyon {
    AddPositionʸDCommand::AddPositionʸDCommand(const Header&h) : 
        PositionCommand(h)
    {
    }

    AddPositionʸDCommand::AddPositionʸDCommand(const Header&h, double Δy) : 
        PositionCommand(h), m_Δy(Δy)
    {
    }

    AddPositionʸDCommand::AddPositionʸDCommand(const AddPositionʸDCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δy(cp.m_Δy)
    {
    }
    
    AddPositionʸDCommand::~AddPositionʸDCommand()
    {
    }
    
    PostCPtr    AddPositionʸDCommand::clone(rebind_k, const Header& h) const 
    {
        return new AddPositionʸDCommand(*this, h);
    }

    void AddPositionʸDCommand::init_meta()
    {
        auto w = writer<AddPositionʸDCommand>();
        w.description("Position AddPosition Command in Y");
        w.property("Δy", &AddPositionʸDCommand::Δy).tag(kTag_Log).tag(kTag_Save);
    }
}
