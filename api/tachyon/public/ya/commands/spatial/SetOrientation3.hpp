////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/SpatialCommand.hpp>
#include <yq/unit/declare.hpp>
#include <yq/vector/Quaternion3.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class SetOrientation³ : public SpatialCommand {
        YQ_OBJECT_DECLARE(SetOrientation³, SpatialCommand)
    public:
        SetOrientation³(TachyonID, hpr_k, Radian hdg, Radian pitch, Radian roll, const Param& p={});
        SetOrientation³(TachyonID, const Quaternion3D&, const Param& p={});
        ~SetOrientation³();
    
        const Quaternion3D&   orientation() const  { return m_orientation; }
        
        static void init_info();
        
        double  w() const { return m_orientation.w; }
        double  x() const { return m_orientation.x; }
        double  y() const { return m_orientation.y; }
        double  z() const { return m_orientation.z; }
        
    private:
        Quaternion3D const  m_orientation;
    };
}
