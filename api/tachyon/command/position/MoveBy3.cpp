////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/command/position/MoveBy3.hpp>
#include <tachyon/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveBy³)

namespace yq::tachyon {
    MoveBy³::MoveBy³(const Header&h) : 
        PositionCommand(h)
    {
    }

    MoveBy³::MoveBy³(const Header&h, const Vector3D& Δ) : 
        PositionCommand(h), m_Δ(Δ)
    {
    }
    
    MoveBy³::MoveBy³(const MoveBy³&cp, const Header&h) : 
        PositionCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    MoveBy³::~MoveBy³()
    {
    }

    PostCPtr    MoveBy³::clone(rebind_k, const Header& h) const 
    {
        return new MoveBy³(*this, h);
    }
   
    void MoveBy³::init_info()
    {
        auto w = writer<MoveBy³>();
        w.description("Position MoveBy Command in 3D");
        w.property("Δx", &MoveBy³::Δx).tag(kTag_Log);
        w.property("Δy", &MoveBy³::Δy).tag(kTag_Log);
        w.property("Δz", &MoveBy³::Δz).tag(kTag_Log);
        w.property("Δ", &MoveBy³::m_Δ).tag(kTag_Save);
    }
}
