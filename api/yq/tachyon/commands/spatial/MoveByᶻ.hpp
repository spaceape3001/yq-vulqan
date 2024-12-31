////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/SpatialCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount
    class MoveByZ : public SpatialCommand {
        YQ_OBJECT_DECLARE(MoveByZ, SpatialCommand)
    public:
        MoveByZ(TachyonID, double Δz, const Param& p={});
        ~MoveByZ();
    
        static void init_info();
        
        double  Δz() const { return m_Δz; }
        
    private:
        double const  m_Δz;
    };
}
