////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/position/MoveBy4.hpp>
#include <tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveBy⁴)

namespace yq::tachyon {
    MoveBy⁴::MoveBy⁴(const Header&h) : 
        PositionCommand(h)
    {
    }

    MoveBy⁴::MoveBy⁴(const Header&h, const Vector4D& Δ) : 
        PositionCommand(h), m_Δ(Δ)
    {
    }
    
    MoveBy⁴::MoveBy⁴(const MoveBy⁴&cp, const Header&h) : 
        PositionCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    MoveBy⁴::~MoveBy⁴()
    {
    }

    PostCPtr    MoveBy⁴::clone(rebind_k, const Header& h) const 
    {
        return new MoveBy⁴(*this, h);
    }
   
    void MoveBy⁴::init_info()
    {
        auto w = writer<MoveBy⁴>();
        w.description("Position MoveBy Command in 4D");
        w.property("Δw", &MoveBy⁴::Δw).tag(kTag_Log);
        w.property("Δx", &MoveBy⁴::Δx).tag(kTag_Log);
        w.property("Δy", &MoveBy⁴::Δy).tag(kTag_Log);
        w.property("Δz", &MoveBy⁴::Δz).tag(kTag_Log);
        w.property("Δ", &MoveBy⁴::m_Δ).tag(kTag_Save);
    }
}
