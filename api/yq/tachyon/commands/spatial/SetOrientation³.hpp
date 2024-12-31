////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/SpatialCommand.hpp>
#include <yq/unit/declare.hpp>
#include <yq/vector/Quaternion3.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class SetOrientation3 : public SpatialCommand {
        YQ_OBJECT_DECLARE(SetOrientation3, SpatialCommand)
    public:
        SetOrientation3(TachyonID, hpr_k, Radian hdg, Radian pitch, Radian roll, const Param& p={});
        SetOrientation3(TachyonID, const Quaternion3D&, const Param& p={});
        ~SetOrientation3();
    
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
