////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/position/AddPositionYCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddPositionʸCommand)

namespace yq::tachyon {
    AddPositionʸCommand::AddPositionʸCommand(const Header&h) : 
        PositionCommand(h)
    {
    }

    AddPositionʸCommand::AddPositionʸCommand(const Header&h, double Δy) : 
        PositionCommand(h), m_Δy(Δy)
    {
    }

    AddPositionʸCommand::AddPositionʸCommand(const AddPositionʸCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δy(cp.m_Δy)
    {
    }
    
    AddPositionʸCommand::~AddPositionʸCommand()
    {
    }
    
    PostCPtr    AddPositionʸCommand::clone(rebind_k, const Header& h) const 
    {
        return new AddPositionʸCommand(*this, h);
    }

    void AddPositionʸCommand::init_meta()
    {
        auto w = writer<AddPositionʸCommand>();
        w.description("Position AddPosition Command in Y");
        w.property("Δy", &AddPositionʸCommand::Δy).tag(kTag_Log).tag(kTag_Save);
    }
}
