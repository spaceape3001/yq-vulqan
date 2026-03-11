////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MoveBy1DCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveBy¹DCommand)

namespace yq::tachyon {
    MoveBy¹DCommand::MoveBy¹DCommand(const Header& h) : 
        PositionCommand(h)
    {
    }

    MoveBy¹DCommand::MoveBy¹DCommand(const Header& h, const Vector1D& Δ) : 
        PositionCommand(h), m_Δ(Δ)
    {
    }

    MoveBy¹DCommand::MoveBy¹DCommand(const MoveBy¹DCommand&cp, const Header&h) : PositionCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    MoveBy¹DCommand::~MoveBy¹DCommand()
    {
    }
    
    PostCPtr    MoveBy¹DCommand::clone(rebind_k, const Header& h) const 
    {
        return new MoveBy¹DCommand(*this, h);
    }

    void MoveBy¹DCommand::init_meta()
    {
        auto w = writer<MoveBy¹DCommand>();
        w.description("Position MoveBy Command in 1D");
        w.property("Δx", &MoveBy¹DCommand::Δx).tag(kTag_Log);
        w.property("Δ", &MoveBy¹DCommand::m_Δ).tag(kTag_Save);
    }
}
