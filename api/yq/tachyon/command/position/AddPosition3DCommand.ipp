////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddPosition3DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddPosition³DCommand)

namespace yq::tachyon {
    AddPosition³DCommand::AddPosition³DCommand(const Header&h) : 
        PositionCommand(h)
    {
    }

    AddPosition³DCommand::AddPosition³DCommand(const Header&h, const Vector3D& Δ) : 
        PositionCommand(h), m_Δ(Δ)
    {
    }
    
    AddPosition³DCommand::AddPosition³DCommand(const AddPosition³DCommand&cp, const Header&h) : 
        PositionCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    AddPosition³DCommand::~AddPosition³DCommand()
    {
    }

    PostCPtr    AddPosition³DCommand::clone(rebind_k, const Header& h) const 
    {
        return new AddPosition³DCommand(*this, h);
    }
   
    void AddPosition³DCommand::init_meta()
    {
        auto w = writer<AddPosition³DCommand>();
        w.description("Position AddPosition Command in 3D");
        w.property("Δx", &AddPosition³DCommand::Δx).tag(kTag_Log);
        w.property("Δy", &AddPosition³DCommand::Δy).tag(kTag_Log);
        w.property("Δz", &AddPosition³DCommand::Δz).tag(kTag_Log);
        w.property("Δ", &AddPosition³DCommand::m_Δ).tag(kTag_Save);
    }
}
