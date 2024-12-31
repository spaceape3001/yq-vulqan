////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/SpatialCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's y-position
    class SetScaleY : public SpatialCommand {
        YQ_OBJECT_DECLARE(SetScaleY, SpatialCommand)
    public:
        SetScaleY(TachyonID, double, const Param& p={});
        ~SetScaleY();
        
        static void init_info();
        
        double  y() const { return m_y; }
        
    private:
        double const  m_y;
    };
}
