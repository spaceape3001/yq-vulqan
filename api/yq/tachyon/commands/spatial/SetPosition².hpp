////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/SpatialCommand.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class SetPosition2 : public SpatialCommand {
        YQ_OBJECT_DECLARE(SetPosition2, SpatialCommand)
    public:
        SetPosition2(TachyonID, const Vector2D&, const Param& p={});
        ~SetPosition2();
    
        const Vector2D&   position() const  { return m_position; }
        
        static void init_info();
        
        double  x() const { return m_position.x; }
        double  y() const { return m_position.y; }
        
    private:
        Vector2D const  m_position;
    };
}
