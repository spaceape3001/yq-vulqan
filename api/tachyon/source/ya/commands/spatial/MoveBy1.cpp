////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/MoveBy1.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveBy¹)

namespace yq::tachyon {
    MoveBy¹::MoveBy¹(const Header& h, const Vector1D& Δ) : 
        SpatialCommand(h), m_Δ(Δ)
    {
    }

    MoveBy¹::MoveBy¹(const MoveBy¹&cp, const Header&h) : SpatialCommand(cp, h), m_Δ(cp.m_Δ)
    {
    }

    MoveBy¹::~MoveBy¹()
    {
    }
    
    PostCPtr    MoveBy¹::clone(rebind_k, const Header& h) const 
    {
        return new MoveBy¹(*this, h);
    }

    void MoveBy¹::init_info()
    {
        auto w = writer<MoveBy¹>();
        w.description("Position MoveBy Command in 1D");
        w.property("Δx", &MoveBy¹::Δx);
    }
}
