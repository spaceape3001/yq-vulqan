////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddPosition3CMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddPosition³CMCommand)

namespace yq::tachyon {
    AddPosition³CMCommand::AddPosition³CMCommand(const Header&h) : 
        PositionCommand(h)
    {
    }

    AddPosition³CMCommand::AddPosition³CMCommand(const Header&h, const Centimeter3D& Δ) : 
        PositionCommand(h), m_Δ(Δ)
    {
    }
    
    AddPosition³CMCommand::AddPosition³CMCommand(const AddPosition³CMCommand&cp, const Header&h) : 
        PositionCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    AddPosition³CMCommand::~AddPosition³CMCommand()
    {
    }

    PostCPtr    AddPosition³CMCommand::clone(rebind_k, const Header& h) const 
    {
        return new AddPosition³CMCommand(*this, h);
    }
   
    void AddPosition³CMCommand::init_meta()
    {
        auto w = writer<AddPosition³CMCommand>();
        w.description("Add Position Command in 3D (meters)");
        w.property("Δx", &AddPosition³CMCommand::Δx).tag(kTag_Log);
        w.property("Δy", &AddPosition³CMCommand::Δy).tag(kTag_Log);
        w.property("Δz", &AddPosition³CMCommand::Δz).tag(kTag_Log);
        w.property("Δ", &AddPosition³CMCommand::m_Δ).tag(kTag_Save);
    }
}
