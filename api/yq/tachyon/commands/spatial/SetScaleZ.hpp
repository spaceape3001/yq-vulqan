////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/SpatialCommand.hpp>
#include <yq/vector/Vector1.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's z-position
    class SetScaleZ : public SpatialCommand {
        YQ_OBJECT_DECLARE(SetScaleZ, SpatialCommand)
    public:
        SetScaleZ(TachyonID, double, const Param& p={});
        ~SetScaleZ();
        
        static void init_info();
        
        double  z() const { return m_z; }
        
    private:
        double const  m_z;
    };
}
