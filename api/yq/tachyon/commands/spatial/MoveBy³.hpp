////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/SpatialCommand.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount
    class MoveBy³ : public SpatialCommand {
        YQ_OBJECT_DECLARE(MoveBy³, SpatialCommand)
    public:
        MoveBy³(TachyonID, const Vector3D&Δ, const Param& p={});
        ~MoveBy³();
    
        const Vector3D&   Δ() const  { return m_Δ; }
        
        static void init_info();
        
        double  Δx() const { return m_Δ.x; }
        double  Δy() const { return m_Δ.y; }
        double  Δz() const { return m_Δ.z; }
        
    private:
        Vector3D const  m_Δ;
    };
}
