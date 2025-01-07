////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <ya/commands/SpatialCommand.hpp>
#include <yq/unit/declare.hpp>
#include <yq/vector/Quaternion3.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class SetOrientation³ : public SpatialCommand {
        YQ_OBJECT_DECLARE(SetOrientation³, SpatialCommand)
    public:
        SetOrientation³(const Header&, hpr_k, Radian hdg, Radian pitch, Radian roll);
        SetOrientation³(const Header&, const Quaternion3D&);
    
        const Quaternion3D&   orientation() const  { return m_orientation; }
        
        static void init_info();
        
        double  w() const { return m_orientation.w; }
        double  x() const { return m_orientation.x; }
        double  y() const { return m_orientation.y; }
        double  z() const { return m_orientation.z; }
    
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:

        SetOrientation³(const SetOrientation³&, const Header&);
        ~SetOrientation³();
        
    private:
        Quaternion3D const  m_orientation;
        
        SetOrientation³(const SetOrientation³&) = delete;
        SetOrientation³(SetOrientation³&&) = delete;
        SetOrientation³& operator=(const SetOrientation³&) = delete;
        SetOrientation³& operator=(SetOrientation³&&) = delete;
    };
}
