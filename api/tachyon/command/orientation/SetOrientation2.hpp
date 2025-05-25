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
    class SetOrientation² : public OrientationCommand {
        YQ_OBJECT_DECLARE(SetOrientation², OrientationCommand)
    public:
        SetOrientation²(const Header&, hpr_k, Radian hdg);
        SetOrientation²(const Header&, const Spinor2D&);
    
        const Spinor2D&   orientation() const  { return m_orientation; }
        
        static void init_info();
        
        double  a() const { return m_orientation.a; }
        double  xy() const { return m_orientation.xy; }
    
        virtual PostCPtr    clone(rebind_k, const Header&) const override;

    protected:

        SetOrientation²(const SetOrientation²&, const Header&);
        ~SetOrientation²();
        
    private:
        Spinor2D const  m_orientation;
        
        SetOrientation²(const SetOrientation²&) = delete;
        SetOrientation²(SetOrientation²&&) = delete;
        SetOrientation²& operator=(const SetOrientation²&) = delete;
        SetOrientation²& operator=(SetOrientation²&&) = delete;
    };
}
