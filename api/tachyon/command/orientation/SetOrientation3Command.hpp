////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/OrientationCommand.hpp>
#include <yq/unit/declare.hpp>
#include <yq/vector/Quaternion3.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class SetOrientation³Command : public OrientationCommand {
        YQ_OBJECT_DECLARE(SetOrientation³Command, OrientationCommand)
    public:
        SetOrientation³Command(const Header&, hpr_k, Radian hdg, Radian pitch, Radian roll);
        SetOrientation³Command(const Header&, const Quaternion3D&);
    
        const Quaternion3D&   orientation() const  { return m_orientation; }
        
        static void init_info();
        
        double  w() const { return m_orientation.w; }
        double  x() const { return m_orientation.x; }
        double  y() const { return m_orientation.y; }
        double  z() const { return m_orientation.z; }
    
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:

        SetOrientation³Command(const SetOrientation³Command&, const Header&);
        ~SetOrientation³Command();
        
    private:
        Quaternion3D const  m_orientation;
        
        SetOrientation³Command(const SetOrientation³Command&) = delete;
        SetOrientation³Command(SetOrientation³Command&&) = delete;
        SetOrientation³Command& operator=(const SetOrientation³Command&) = delete;
        SetOrientation³Command& operator=(SetOrientation³Command&&) = delete;
    };
}
