////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/SpatialCommand.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class SetPosition3 : public SpatialCommand {
        YQ_OBJECT_DECLARE(SetPosition3, SpatialCommand)
    public:
        SetPosition3(TachyonID, const Vector3D&, const Param& p={});
        ~SetPosition3();
    
        const Vector3D&   position() const  { return m_position; }
        
        static void init_info();
        
        double  x() const { return m_position.x; }
        double  y() const { return m_position.y; }
        double  z() const { return m_position.z; }
        
    private:
        Vector3D const  m_position;
    };
}
