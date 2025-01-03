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

    //! Instructs an object to yaw (ie, around the local body Z-axis) by the given amount
    class YawBy : public SpatialCommand {
        YQ_OBJECT_DECLARE(YawBy, SpatialCommand)
    public:
        YawBy(TachyonID, Radian θ, const Param& p={});
        ~YawBy();
    
        static void init_info();
        
        Radian  θ() const { return m_θ; }
        
    private:
        Radian const  m_θ;
    };
}
