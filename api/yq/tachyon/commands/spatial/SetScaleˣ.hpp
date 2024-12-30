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
    class SetScaleˣ : public SpatialCommand {
        YQ_OBJECT_DECLARE(SetScaleˣ, SpatialCommand)
    public:
        SetScaleˣ(TachyonID, double, const Param& p={});
        ~SetScaleˣ();
        
        static void init_info();
        
        double  x() const { return m_x; }
        
    private:
        double const  m_x;
    };
}
