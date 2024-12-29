////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MoveBy³.hpp"
#include <yq/tachyon/api/CommandInfoWriter.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::MoveBy³)

namespace yq::tachyon {
    MoveBy³::MoveBy³(TachyonID tid, const Vector3D& Δ, const Param& p) : 
        TachyonCommand(tid, p), m_Δ(Δ)
    {
    }
    
    MoveBy³::~MoveBy³()
    {
    }
    
    void MoveBy³::init_info()
    {
        auto w = writer<MoveBy³>();
        w.description("Position MoveBy Command in ³D");
        w.property("Δx", &MoveBy³::Δx);
        w.property("Δy", &MoveBy³::Δy);
        w.property("Δz", &MoveBy³::Δz);
    }
}
