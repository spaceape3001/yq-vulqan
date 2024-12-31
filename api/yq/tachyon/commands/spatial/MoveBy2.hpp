////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/SpatialCommand.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount
    class MoveBy2 : public SpatialCommand {
        YQ_OBJECT_DECLARE(MoveBy2, SpatialCommand)
    public:
        MoveBy2(TachyonID, const Vector2D&Δ, const Param& p={});
        ~MoveBy2();
    
        const Vector2D&   Δ() const  { return m_Δ; }
        
        static void init_info();
        
        double  Δx() const { return m_Δ.x; }
        double  Δy() const { return m_Δ.y; }
        
    private:
        Vector2D const  m_Δ;
    };
}
