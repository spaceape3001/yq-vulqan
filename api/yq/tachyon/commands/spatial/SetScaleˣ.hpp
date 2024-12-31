////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/SpatialCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's x-position
    class SetScaleX : public SpatialCommand {
        YQ_OBJECT_DECLARE(SetScaleX, SpatialCommand)
    public:
        SetScaleX(TachyonID, double, const Param& p={});
        ~SetScaleX();
        
        static void init_info();
        
        double  x() const { return m_x; }
        
    private:
        double const  m_x;
    };
}
