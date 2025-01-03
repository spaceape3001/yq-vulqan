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
    class SetPositionʸ : public SpatialCommand {
        YQ_OBJECT_DECLARE(SetPositionʸ, SpatialCommand)
    public:
        SetPositionʸ(TachyonID, double, const Param& p={});
        ~SetPositionʸ();
        
        static void init_info();
        
        double  y() const { return m_y; }
        
    private:
        double const  m_y;
    };
}
