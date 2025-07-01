////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/position/MoveBy4Command.hpp>
#include <tachyon/api/CommandMetaWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveBy⁴Command)

namespace yq::tachyon {
    MoveBy⁴Command::MoveBy⁴Command(const Header&h) : 
        PositionCommand(h)
    {
    }

    MoveBy⁴Command::MoveBy⁴Command(const Header&h, const Vector4D& Δ) : 
        PositionCommand(h), m_Δ(Δ)
    {
    }
    
    MoveBy⁴Command::MoveBy⁴Command(const MoveBy⁴Command&cp, const Header&h) : 
        PositionCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    MoveBy⁴Command::~MoveBy⁴Command()
    {
    }

    PostCPtr    MoveBy⁴Command::clone(rebind_k, const Header& h) const 
    {
        return new MoveBy⁴Command(*this, h);
    }
   
    void MoveBy⁴Command::init_info()
    {
        auto w = writer<MoveBy⁴Command>();
        w.description("Position MoveBy Command in 4D");
        w.property("Δw", &MoveBy⁴Command::Δw).tag(kTag_Log);
        w.property("Δx", &MoveBy⁴Command::Δx).tag(kTag_Log);
        w.property("Δy", &MoveBy⁴Command::Δy).tag(kTag_Log);
        w.property("Δz", &MoveBy⁴Command::Δz).tag(kTag_Log);
        w.property("Δ", &MoveBy⁴Command::m_Δ).tag(kTag_Save);
    }
}
