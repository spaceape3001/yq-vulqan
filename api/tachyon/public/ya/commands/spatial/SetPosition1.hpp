////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/SpatialCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class SetPosition¹ : public SpatialCommand {
        YQ_OBJECT_DECLARE(SetPosition¹, SpatialCommand)
    public:
        SetPosition¹(TachyonID, const Vector1D&, const Param& p={});
        ~SetPosition¹();
    
        const Vector1D&   position() const  { return m_position; }
        
        static void init_info();
        
        double  x() const { return m_position.x; }
        
    private:
        Vector1D const  m_position;
    };
}
