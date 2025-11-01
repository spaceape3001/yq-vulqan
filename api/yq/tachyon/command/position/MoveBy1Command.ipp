////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/position/MoveBy1Command.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveBy¹Command)

namespace yq::tachyon {
    MoveBy¹Command::MoveBy¹Command(const Header& h) : 
        PositionCommand(h)
    {
    }

    MoveBy¹Command::MoveBy¹Command(const Header& h, const Vector1D& Δ) : 
        PositionCommand(h), m_Δ(Δ)
    {
    }

    MoveBy¹Command::MoveBy¹Command(const MoveBy¹Command&cp, const Header&h) : PositionCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    MoveBy¹Command::~MoveBy¹Command()
    {
    }
    
    PostCPtr    MoveBy¹Command::clone(rebind_k, const Header& h) const 
    {
        return new MoveBy¹Command(*this, h);
    }

    void MoveBy¹Command::init_meta()
    {
        auto w = writer<MoveBy¹Command>();
        w.description("Position MoveBy Command in 1D");
        w.property("Δx", &MoveBy¹Command::Δx).tag(kTag_Log);
        w.property("Δ", &MoveBy¹Command::m_Δ).tag(kTag_Save);
    }
}
