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
    class SetPositionX : public SpatialCommand {
        YQ_OBJECT_DECLARE(SetPositionX, SpatialCommand)
    public:
        SetPositionX(TachyonID, double, const Param& p={});
        ~SetPositionX();
        
        static void init_info();
        
        double  x() const { return m_x; }
        
    private:
        double const  m_x;
    };
}
