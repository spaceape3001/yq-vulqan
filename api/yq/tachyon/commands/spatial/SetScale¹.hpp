////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/SpatialCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's scale
    class SetScale¹ : public SpatialCommand {
        YQ_OBJECT_DECLARE(SetScale¹, SpatialCommand)
    public:
        SetScale¹(TachyonID, const Vector1D&, const Param& p={});
        ~SetScale¹();
    
        const Vector1D&   scale() const  { return m_scale; }
        
        static void init_info();
        
        double  x() const { return m_scale.x; }
        
    private:
        Vector1D const  m_scale;
    };
}
