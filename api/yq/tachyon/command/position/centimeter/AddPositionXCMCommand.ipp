////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddPositionXCMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddPositionˣCMCommand)

namespace yq::tachyon {
    AddPositionˣCMCommand::AddPositionˣCMCommand(const Header&h) : 
        PositionCommand(h)
    {
    }

    AddPositionˣCMCommand::AddPositionˣCMCommand(const Header&h, Centimeter Δx) : 
        PositionCommand(h), m_Δx(Δx)
    {
    }
    
    AddPositionˣCMCommand::AddPositionˣCMCommand(const AddPositionˣCMCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δx(cp.m_Δx)
    {
    }

    AddPositionˣCMCommand::~AddPositionˣCMCommand()
    {
    }
    
    PostCPtr    AddPositionˣCMCommand::clone(rebind_k, const Header&h) const 
    {
        return new AddPositionˣCMCommand(*this, h);
    }

    void AddPositionˣCMCommand::init_meta()
    {
        auto w = writer<AddPositionˣCMCommand>();
        w.description("Add Position Command in X (meters)");
        w.property("Δx", &AddPositionˣCMCommand::Δx).tag(kTag_Log).tag(kTag_Save);
    }
}
