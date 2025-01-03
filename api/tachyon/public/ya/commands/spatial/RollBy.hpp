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

    //! Instructs an object to roll (ie, around the local body X-axis) by the given amount
    class RollBy : public SpatialCommand {
        YQ_OBJECT_DECLARE(RollBy, SpatialCommand)
    public:
        RollBy(TachyonID, Radian θ, const Param& p={});
        ~RollBy();
    
        static void init_info();
        
        Radian  θ() const { return m_θ; }
        
    private:
        Radian const  m_θ;
    };
}
