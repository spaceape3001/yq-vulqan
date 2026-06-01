////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddPosition4MCommand.hpp"
#include <yq/tachyon/tags.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddPosition⁴MCommand)

namespace yq::tachyon {
    AddPosition⁴MCommand::AddPosition⁴MCommand(const Header&h) : 
        PositionCommand(h)
    {
    }

    AddPosition⁴MCommand::AddPosition⁴MCommand(const Header&h, const Meter4D& Δ) : 
        PositionCommand(h), m_Δ(Δ)
    {
    }
    
    AddPosition⁴MCommand::AddPosition⁴MCommand(const AddPosition⁴MCommand&cp, const Header&h) : 
        PositionCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    AddPosition⁴MCommand::~AddPosition⁴MCommand()
    {
    }

    PostCPtr    AddPosition⁴MCommand::clone(rebind_k, const Header& h) const 
    {
        return new AddPosition⁴MCommand(*this, h);
    }
   
    void AddPosition⁴MCommand::init_meta()
    {
        auto w = writer<AddPosition⁴MCommand>();
        w.description("Position AddPosition Command in 4D");
        w.property("Δw", &AddPosition⁴MCommand::Δw).tag(kTag_Log);
        w.property("Δx", &AddPosition⁴MCommand::Δx).tag(kTag_Log);
        w.property("Δy", &AddPosition⁴MCommand::Δy).tag(kTag_Log);
        w.property("Δz", &AddPosition⁴MCommand::Δz).tag(kTag_Log);
        w.property("Δ", &AddPosition⁴MCommand::m_Δ).tag(kTag_Save);
    }
}
