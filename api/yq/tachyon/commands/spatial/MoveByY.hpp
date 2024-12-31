////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/SpatialCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount
    class MoveByY : public SpatialCommand {
        YQ_OBJECT_DECLARE(MoveByY, SpatialCommand)
    public:
        MoveByY(TachyonID, double Δy, const Param& p={});
        ~MoveByY();
    
        static void init_info();
        
        double  Δy() const { return m_Δy; }
        
    private:
        double const  m_Δy;
    };
}
