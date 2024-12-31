////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/SpatialCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount
    class MoveByX : public SpatialCommand {
        YQ_OBJECT_DECLARE(MoveByX, SpatialCommand)
    public:
        MoveByX(TachyonID, double Δx, const Param& p={});
        ~MoveByX();
    
        static void init_info();
        
        double  Δx() const { return m_Δx; }
        
    private:
        double const  m_Δx;
    };
}
