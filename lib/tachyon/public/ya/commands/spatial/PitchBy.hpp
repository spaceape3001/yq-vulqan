////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/SpatialCommand.hpp>
#include <yq/unit/declare.hpp>
#include <yq/unit/MKS.hpp>

namespace yq::tachyon {

    //! Instructs an object to pitch (ie, around the local body Y-axis) by the given amount
    class PitchBy : public SpatialCommand {
        YQ_OBJECT_DECLARE(PitchBy, SpatialCommand)
    public:
        PitchBy(TachyonID, Radian θ, const Param& p={});
        ~PitchBy();
    
        static void init_info();
        
        Radian  θ() const { return m_θ; }
        
    private:
        Radian const  m_θ;
    };
}
