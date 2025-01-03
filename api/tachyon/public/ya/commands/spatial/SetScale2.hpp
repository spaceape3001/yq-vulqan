////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/SpatialCommand.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class SetScale2 : public SpatialCommand {
        YQ_OBJECT_DECLARE(SetScale2, SpatialCommand)
    public:
        SetScale2(TachyonID, const Vector2D&, const Param& p={});
        ~SetScale2();
    
        const Vector2D&   scale() const  { return m_scale; }
        
        static void init_info();
        
        double  x() const { return m_scale.x; }
        double  y() const { return m_scale.y; }
        
    private:
        Vector2D const  m_scale;
    };
}
