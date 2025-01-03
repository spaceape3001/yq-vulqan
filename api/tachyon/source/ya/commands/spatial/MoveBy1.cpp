////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/commands/spatial/MoveBy1.hpp>
#include <yt/msg/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveBy¹)

namespace yq::tachyon {
    MoveBy¹::MoveBy¹(TachyonID tid, const Vector1D& Δ, const Param& p) : 
        SpatialCommand(tid, p), m_Δ(Δ)
    {
    }
    
    MoveBy¹::~MoveBy¹()
    {
    }
    
    void MoveBy¹::init_info()
    {
        auto w = writer<MoveBy¹>();
        w.description("Position MoveBy Command in 1D");
        w.property("Δx", &MoveBy¹::Δx);
    }
}
