////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddPosition1DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddPosition¹DCommand)

namespace yq::tachyon {
    AddPosition¹DCommand::AddPosition¹DCommand(const Header& h) : 
        PositionCommand(h)
    {
    }

    AddPosition¹DCommand::AddPosition¹DCommand(const Header& h, const Vector1D& Δ) : 
        PositionCommand(h), m_Δ(Δ)
    {
    }

    AddPosition¹DCommand::AddPosition¹DCommand(const AddPosition¹DCommand&cp, const Header&h) : PositionCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    AddPosition¹DCommand::~AddPosition¹DCommand()
    {
    }
    
    PostCPtr    AddPosition¹DCommand::clone(rebind_k, const Header& h) const 
    {
        return new AddPosition¹DCommand(*this, h);
    }

    void AddPosition¹DCommand::init_meta()
    {
        auto w = writer<AddPosition¹DCommand>();
        w.description("Position AddPosition Command in 1D");
        w.property("Δx", &AddPosition¹DCommand::Δx).tag(kTag_Log);
        w.property("Δ", &AddPosition¹DCommand::m_Δ).tag(kTag_Save);
    }
}
