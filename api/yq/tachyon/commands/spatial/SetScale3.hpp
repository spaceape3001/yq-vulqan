////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/SpatialCommand.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class SetScale3 : public SpatialCommand {
        YQ_OBJECT_DECLARE(SetScale3, SpatialCommand)
    public:
        SetScale3(TachyonID, const Vector3D&, const Param& p={});
        ~SetScale3();
    
        const Vector3D&   scale() const  { return m_scale; }
        
        static void init_info();
        
        double  x() const { return m_scale.x; }
        double  y() const { return m_scale.y; }
        double  z() const { return m_scale.z; }
        
    private:
        Vector3D const  m_scale;
    };
}
