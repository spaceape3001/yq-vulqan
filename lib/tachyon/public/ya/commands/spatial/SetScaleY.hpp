////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/SpatialCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's y-position
    class SetScaleʸ : public SpatialCommand {
        YQ_OBJECT_DECLARE(SetScaleʸ, SpatialCommand)
    public:
        SetScaleʸ(TachyonID, double, const Param& p={});
        ~SetScaleʸ();
        
        static void init_info();
        
        double  y() const { return m_y; }
        
    private:
        double const  m_y;
    };
}
