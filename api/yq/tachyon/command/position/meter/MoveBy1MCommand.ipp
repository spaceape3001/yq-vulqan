////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MoveBy1MCommand.hpp"
#include <yq/tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveBy¹MCommand)

namespace yq::tachyon {
    MoveBy¹MCommand::MoveBy¹MCommand(const Header& h) : 
        PositionCommand(h)
    {
    }

    MoveBy¹MCommand::MoveBy¹MCommand(const Header& h, const Meter1D& Δ) : 
        PositionCommand(h), m_Δ(Δ)
    {
    }

    MoveBy¹MCommand::MoveBy¹MCommand(const MoveBy¹MCommand&cp, const Header&h) : PositionCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    MoveBy¹MCommand::~MoveBy¹MCommand()
    {
    }
    
    PostCPtr    MoveBy¹MCommand::clone(rebind_k, const Header& h) const 
    {
        return new MoveBy¹MCommand(*this, h);
    }

    void MoveBy¹MCommand::init_meta()
    {
        auto w = writer<MoveBy¹MCommand>();
        w.description("Position MoveBy Command in 1D");
        w.property("Δx", &MoveBy¹MCommand::Δx).tag(kTag_Log);
        w.property("Δ", &MoveBy¹MCommand::m_Δ).tag(kTag_Save);
    }
}
