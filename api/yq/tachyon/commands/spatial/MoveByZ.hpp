////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/SpatialCommand.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount
    class MoveByᶻ : public SpatialCommand {
        YQ_OBJECT_DECLARE(MoveByᶻ, SpatialCommand)
    public:
        MoveByᶻ(TachyonID, double Δz, const Param& p={});
        ~MoveByᶻ();
    
        static void init_info();
        
        double  Δz() const { return m_Δz; }
        
    private:
        double const  m_Δz;
    };
}
