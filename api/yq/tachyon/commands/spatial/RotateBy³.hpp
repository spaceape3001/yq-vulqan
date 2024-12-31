////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/commands/SpatialCommand.hpp>
#include <yq/unit/declare.hpp>
#include <yq/vector/Quaternion3.hpp>

namespace yq::tachyon {

    //! Instructs an object to adjust (self-increment) their position by given amount
    class RotateBy3 : public SpatialCommand {
        YQ_OBJECT_DECLARE(RotateBy3, SpatialCommand)
    public:
        RotateBy3(TachyonID, const Quaternion3D&δ, const Param& p={});
        RotateBy3(TachyonID, const unit::Radian3D&δ, const Param& p={});
        ~RotateBy3();
    
        const Quaternion3D&   δ() const  { return m_δ; }
        
        static void init_info();
        
        double δw() const { return m_δ.w; }
        double δx() const { return m_δ.x; }
        double δy() const { return m_δ.y; }
        double δz() const { return m_δ.z; }
        
    private:
        Quaternion3D const  m_δ;
    };
}
