////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddPositionXMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddPositionXMCommand)

namespace yq::tachyon {
    AddPositionXMCommand::AddPositionXMCommand(const Header&h) : 
        PositionCommand(h)
    {
    }

    AddPositionXMCommand::AddPositionXMCommand(const Header&h, Meter Δx) : 
        PositionCommand(h), m_Δx(Δx)
    {
    }
    
    AddPositionXMCommand::AddPositionXMCommand(const AddPositionXMCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δx(cp.m_Δx)
    {
    }

    AddPositionXMCommand::~AddPositionXMCommand()
    {
    }
    
    PostCPtr    AddPositionXMCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddPositionXMCommand(*this, h);
    }

    void AddPositionXMCommand::init_meta()
    {
        auto w = writer<AddPositionXMCommand>();
        w.description("Add Position Command in X (meters)");
        w.property("Δx", &AddPositionXMCommand::Δx).tag(kTag_Log).tag(kTag_Save);
    }
}
