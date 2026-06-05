////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MoveBy1CMCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveBy¹CMCommand)

namespace yq::tachyon {
    MoveBy¹CMCommand::MoveBy¹CMCommand(const Header& h) : 
        PositionCommand(h)
    {
    }

    MoveBy¹CMCommand::MoveBy¹CMCommand(const Header& h, const Centimeter1D& Δ) : 
        PositionCommand(h), m_Δ(Δ)
    {
    }

    MoveBy¹CMCommand::MoveBy¹CMCommand(const MoveBy¹CMCommand&cp, const Header&h) : PositionCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    MoveBy¹CMCommand::~MoveBy¹CMCommand()
    {
    }
    
    PostCPtr    MoveBy¹CMCommand::clone(rebind_k, const Header& h) const 
    {
        return new MoveBy¹CMCommand(*this, h);
    }

    void MoveBy¹CMCommand::init_meta()
    {
        auto w = writer<MoveBy¹CMCommand>();
        w.description("Position MoveBy Command in 1D");
        w.property("Δx", &MoveBy¹CMCommand::Δx).tag(kTag_Log);
        w.property("Δ", &MoveBy¹CMCommand::m_Δ).tag(kTag_Save);
    }
}
