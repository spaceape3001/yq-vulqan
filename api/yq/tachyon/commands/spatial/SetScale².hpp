////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/SpatialCommand.hpp>
#include <yq/vector/Vector2.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class SetScale² : public SpatialCommand {
        YQ_OBJECT_DECLARE(SetScale², SpatialCommand)
    public:
        SetScale²(TachyonID, const Vector2D&, const Param& p={});
        ~SetScale²();
    
        const Vector2D&   scale() const  { return m_scale; }
        
        static void init_info();
        
        double  x() const { return m_scale.x; }
        double  y() const { return m_scale.y; }
        
    private:
        Vector2D const  m_scale;
    };
}
