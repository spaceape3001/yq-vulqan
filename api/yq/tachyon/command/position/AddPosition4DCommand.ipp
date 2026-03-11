////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddPosition4DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddPosition⁴DCommand)

namespace yq::tachyon {
    AddPosition⁴DCommand::AddPosition⁴DCommand(const Header&h) : 
        PositionCommand(h)
    {
    }

    AddPosition⁴DCommand::AddPosition⁴DCommand(const Header&h, const Vector4D& Δ) : 
        PositionCommand(h), m_Δ(Δ)
    {
    }
    
    AddPosition⁴DCommand::AddPosition⁴DCommand(const AddPosition⁴DCommand&cp, const Header&h) : 
        PositionCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    AddPosition⁴DCommand::~AddPosition⁴DCommand()
    {
    }

    PostCPtr    AddPosition⁴DCommand::clone(rebind_k, const Header& h) const 
    {
        return new AddPosition⁴DCommand(*this, h);
    }
   
    void AddPosition⁴DCommand::init_meta()
    {
        auto w = writer<AddPosition⁴DCommand>();
        w.description("Position AddPosition Command in 4D");
        w.property("Δw", &AddPosition⁴DCommand::Δw).tag(kTag_Log);
        w.property("Δx", &AddPosition⁴DCommand::Δx).tag(kTag_Log);
        w.property("Δy", &AddPosition⁴DCommand::Δy).tag(kTag_Log);
        w.property("Δz", &AddPosition⁴DCommand::Δz).tag(kTag_Log);
        w.property("Δ", &AddPosition⁴DCommand::m_Δ).tag(kTag_Save);
    }
}
