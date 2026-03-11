////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddPosition2DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddPosition²DCommand)

namespace yq::tachyon {
    AddPosition²DCommand::AddPosition²DCommand(const Header&h) : 
        PositionCommand(h)
    {
    }
    
    AddPosition²DCommand::AddPosition²DCommand(const Header&h, const Vector2D& Δ) : 
        PositionCommand(h), m_Δ(Δ)
    {
    }

    AddPosition²DCommand::AddPosition²DCommand(const AddPosition²DCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    AddPosition²DCommand::~AddPosition²DCommand()
    {
    }
    
    PostCPtr    AddPosition²DCommand::clone(rebind_k, const Header& h) const 
    {
        return new AddPosition²DCommand(*this, h);
    }

    void AddPosition²DCommand::init_meta()
    {
        auto w = writer<AddPosition²DCommand>();
        w.description("Position AddPosition Command in 2D");
        w.property("Δx", &AddPosition²DCommand::Δx).tag(kTag_Log);
        w.property("Δy", &AddPosition²DCommand::Δy).tag(kTag_Log);
        w.property("Δ", &AddPosition²DCommand::m_Δ).tag(kTag_Save);
    }
}
