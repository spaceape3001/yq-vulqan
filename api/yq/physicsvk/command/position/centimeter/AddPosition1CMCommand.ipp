////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddPosition1CMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddPosition¹CMCommand)

namespace yq::tachyon {
    AddPosition¹CMCommand::AddPosition¹CMCommand(const Header& h) : 
        PositionCommand(h)
    {
    }

    AddPosition¹CMCommand::AddPosition¹CMCommand(const Header& h, const Centimeter1D& Δ) : 
        PositionCommand(h), m_Δ(Δ)
    {
    }

    AddPosition¹CMCommand::AddPosition¹CMCommand(const AddPosition¹CMCommand&cp, const Header&h) : PositionCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    AddPosition¹CMCommand::~AddPosition¹CMCommand()
    {
    }
    
    PostCPtr    AddPosition¹CMCommand::clone(rebind_k, const Header& h) const 
    {
        return new AddPosition¹CMCommand(*this, h);
    }

    void AddPosition¹CMCommand::init_meta()
    {
        auto w = writer<AddPosition¹CMCommand>();
        w.description("Position AddPosition Command in 1D");
        w.property("Δx", &AddPosition¹CMCommand::Δx).tag(kTag_Log);
        w.property("Δ", &AddPosition¹CMCommand::m_Δ).tag(kTag_Save);
    }
}
