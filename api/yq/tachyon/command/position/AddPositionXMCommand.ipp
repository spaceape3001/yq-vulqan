////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddPositionXMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddPositionˣMCommand)

namespace yq::tachyon {
    AddPositionˣMCommand::AddPositionˣMCommand(const Header&h) : 
        PositionCommand(h)
    {
    }

    AddPositionˣMCommand::AddPositionˣMCommand(const Header&h, Meter Δx) : 
        PositionCommand(h), m_Δx(Δx)
    {
    }
    
    AddPositionˣMCommand::AddPositionˣMCommand(const AddPositionˣMCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δx(cp.m_Δx)
    {
    }

    AddPositionˣMCommand::~AddPositionˣMCommand()
    {
    }
    
    PostCPtr    AddPositionˣMCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddPositionˣMCommand(*this, h);
    }

    void AddPositionˣMCommand::init_meta()
    {
        auto w = writer<AddPositionˣMCommand>();
        w.description("Add Position Command in X (meters)");
        w.property("Δx", &AddPositionˣMCommand::Δx).tag(kTag_Log).tag(kTag_Save);
    }
}
