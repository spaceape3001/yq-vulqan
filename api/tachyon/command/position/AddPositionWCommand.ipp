////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/position/AddPositionWCommand.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddPositionʷCommand)

namespace yq::tachyon {
    AddPositionʷCommand::AddPositionʷCommand(const Header&h) : 
        PositionCommand(h)
    {
    }

    AddPositionʷCommand::AddPositionʷCommand(const Header&h, double Δw) : 
        PositionCommand(h), m_Δw(Δw)
    {
    }
    
    AddPositionʷCommand::AddPositionʷCommand(const AddPositionʷCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δw(cp.m_Δw)
    {
    }

    AddPositionʷCommand::~AddPositionʷCommand()
    {
    }
    
    PostCPtr    AddPositionʷCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddPositionʷCommand(*this, h);
    }

    void AddPositionʷCommand::init_meta()
    {
        auto w = writer<AddPositionʷCommand>();
        w.description("Position AddPosition Command in X");
        w.property("Δw", &AddPositionʷCommand::Δw).tag(kTag_Log).tag(kTag_Save);
    }
}
