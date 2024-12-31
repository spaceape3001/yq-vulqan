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
    class SetScaleᶻ : public SpatialCommand {
        YQ_OBJECT_DECLARE(SetScaleᶻ, SpatialCommand)
    public:
        SetScaleᶻ(TachyonID, double, const Param& p={});
        ~SetScaleᶻ();
        
        static void init_info();
        
        double  z() const { return m_z; }
        
    private:
        double const  m_z;
    };
}
