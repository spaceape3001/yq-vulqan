////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddPosition4CMCommand.hpp"
#include <yq/tachyon/tags.hpp>
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddPosition⁴CMCommand)

namespace yq::tachyon {
    AddPosition⁴CMCommand::AddPosition⁴CMCommand(const Header&h) : 
        PositionCommand(h)
    {
    }

    AddPosition⁴CMCommand::AddPosition⁴CMCommand(const Header&h, const Centimeter4D& Δ) : 
        PositionCommand(h), m_Δ(Δ)
    {
    }
    
    AddPosition⁴CMCommand::AddPosition⁴CMCommand(const AddPosition⁴CMCommand&cp, const Header&h) : 
        PositionCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    AddPosition⁴CMCommand::~AddPosition⁴CMCommand()
    {
    }

    PostCPtr    AddPosition⁴CMCommand::clone(rebind_k, const Header& h) const 
    {
        return new AddPosition⁴CMCommand(*this, h);
    }
   
    void AddPosition⁴CMCommand::init_meta()
    {
        auto w = writer<AddPosition⁴CMCommand>();
        w.description("Position AddPosition Command in 4D");
        w.property("Δw", &AddPosition⁴CMCommand::Δw).tag(kTag_Log);
        w.property("Δx", &AddPosition⁴CMCommand::Δx).tag(kTag_Log);
        w.property("Δy", &AddPosition⁴CMCommand::Δy).tag(kTag_Log);
        w.property("Δz", &AddPosition⁴CMCommand::Δz).tag(kTag_Log);
        w.property("Δ", &AddPosition⁴CMCommand::m_Δ).tag(kTag_Save);
    }
}
