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
    class SetPositionY : public SpatialCommand {
        YQ_OBJECT_DECLARE(SetPositionY, SpatialCommand)
    public:
        SetPositionY(TachyonID, double, const Param& p={});
        ~SetPositionY();
        
        static void init_info();
        
        double  y() const { return m_y; }
        
    private:
        double const  m_y;
    };
}
