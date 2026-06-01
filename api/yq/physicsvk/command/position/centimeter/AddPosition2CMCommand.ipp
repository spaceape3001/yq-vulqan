////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddPosition2CMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddPosition²CMCommand)

namespace yq::tachyon {
    AddPosition²CMCommand::AddPosition²CMCommand(const Header&h) : 
        PositionCommand(h)
    {
    }
    
    AddPosition²CMCommand::AddPosition²CMCommand(const Header&h, const Centimeter2D& Δ) : 
        PositionCommand(h), m_Δ(Δ)
    {
    }

    AddPosition²CMCommand::AddPosition²CMCommand(const AddPosition²CMCommand& cp, const Header&h) : 
        PositionCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    AddPosition²CMCommand::~AddPosition²CMCommand()
    {
    }
    
    PostCPtr    AddPosition²CMCommand::clone(rebind_k, const Header& h) const 
    {
        return new AddPosition²CMCommand(*this, h);
    }

    void AddPosition²CMCommand::init_meta()
    {
        auto w = writer<AddPosition²CMCommand>();
        w.description("Add Position Command in 2D (meters)");
        w.property("Δx", &AddPosition²CMCommand::Δx).tag(kTag_Log);
        w.property("Δy", &AddPosition²CMCommand::Δy).tag(kTag_Log);
        w.property("Δ", &AddPosition²CMCommand::m_Δ).tag(kTag_Save);
    }
}
