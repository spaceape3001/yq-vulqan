////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AddPosition1MCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::AddPosition¹MCommand)

namespace yq::tachyon {
    AddPosition¹MCommand::AddPosition¹MCommand(const Header& h) : 
        PositionCommand(h)
    {
    }

    AddPosition¹MCommand::AddPosition¹MCommand(const Header& h, const Meter1D& Δ) : 
        PositionCommand(h), m_Δ(Δ)
    {
    }

    AddPosition¹MCommand::AddPosition¹MCommand(const AddPosition¹MCommand&cp, const Header&h) : PositionCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    AddPosition¹MCommand::~AddPosition¹MCommand()
    {
    }
    
    PostCPtr    AddPosition¹MCommand::clone(rebind_k, const Header& h) const 
    {
        return new AddPosition¹MCommand(*this, h);
    }

    void AddPosition¹MCommand::init_meta()
    {
        auto w = writer<AddPosition¹MCommand>();
        w.description("Position AddPosition Command in 1D");
        w.property("Δx", &AddPosition¹MCommand::Δx).tag(kTag_Log);
        w.property("Δ", &AddPosition¹MCommand::m_Δ).tag(kTag_Save);
    }
}
