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
    class SetPositionˣ : public SpatialCommand {
        YQ_OBJECT_DECLARE(SetPositionˣ, SpatialCommand)
    public:
        SetPositionˣ(TachyonID, double, const Param& p={});
        ~SetPositionˣ();
        
        static void init_info();
        
        double  x() const { return m_x; }
        
    private:
        double const  m_x;
    };
}
