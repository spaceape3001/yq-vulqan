////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/position/AddPositionXCommand.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddPositionˣCommand)

namespace yq::tachyon {
    AddPositionˣCommand::AddPositionˣCommand(const Header&h) : 
        PositionCommand(h)
    {
    }

    AddPositionˣCommand::AddPositionˣCommand(const Header&h, double Δx) : 
        PositionCommand(h), m_Δx(Δx)
    {
    }
    
    AddPositionˣCommand::AddPositionˣCommand(const AddPositionˣCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δx(cp.m_Δx)
    {
    }

    AddPositionˣCommand::~AddPositionˣCommand()
    {
    }
    
    PostCPtr    AddPositionˣCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddPositionˣCommand(*this, h);
    }

    void AddPositionˣCommand::init_info()
    {
        auto w = writer<AddPositionˣCommand>();
        w.description("Position AddPosition Command in X");
        w.property("Δx", &AddPositionˣCommand::Δx).tag(kTag_Log).tag(kTag_Save);
    }
}
