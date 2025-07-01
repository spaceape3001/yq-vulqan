////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/command/spatial/OrientationCommand.hpp>
#include <yq/unit/declare.hpp>
#include <yq/vector/Spinor2.hpp>

namespace yq::tachyon {

    //! Instructs an object to set it's position
    class SetOrientation²Command : public OrientationCommand {
        YQ_OBJECT_DECLARE(SetOrientation²Command, OrientationCommand)
    public:
        SetOrientation²Command(const Header&, hpr_k, Radian hdg);
        SetOrientation²Command(const Header&, const Spinor2D&);
    
        const Spinor2D&   orientation() const  { return m_orientation; }
        
        static void init_meta();
        
        double  a() const { return m_orientation.a; }
        double  xy() const { return m_orientation.xy; }
    
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:

        SetOrientation²Command(const SetOrientation²Command&, const Header&);
        ~SetOrientation²Command();
        
    private:
        Spinor2D const  m_orientation;
        
        SetOrientation²Command(const SetOrientation²Command&) = delete;
        SetOrientation²Command(SetOrientation²Command&&) = delete;
        SetOrientation²Command& operator=(const SetOrientation²Command&) = delete;
        SetOrientation²Command& operator=(SetOrientation²Command&&) = delete;
    };
}
