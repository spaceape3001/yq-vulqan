////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/SpatialCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class SetScale1 : public SpatialCommand {
        YQ_OBJECT_DECLARE(SetScale1, SpatialCommand)
    public:
        SetScale1(TachyonID, const Vector1D&, const Param& p={});
        ~SetScale1();
    
        const Vector1D&   scale() const  { return m_scale; }
        
        static void init_info();
        
        double  x() const { return m_scale.x; }
        
    private:
        Vector1D const  m_scale;
    };
}
