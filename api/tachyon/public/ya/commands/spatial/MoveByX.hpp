////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/SpatialCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount
    class MoveByˣ : public SpatialCommand {
        YQ_OBJECT_DECLARE(MoveByˣ, SpatialCommand)
    public:
        MoveByˣ(TachyonID, double Δx, const Param& p={});
        ~MoveByˣ();
    
        static void init_info();
        
        double  Δx() const { return m_Δx; }
        
    private:
        double const  m_Δx;
    };
}
