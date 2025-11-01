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

    //! Instructs an object to adjust (self-increment) their position by given amount
    class RotateBy²Command : public OrientationCommand {
        YQ_OBJECT_DECLARE(RotateBy²Command, OrientationCommand)
    public:
        RotateBy²Command(const Header&, const Spinor2D&δ);
        RotateBy²Command(const Header&, Radian δ);
    
        const Spinor2D&   δ() const  { return m_δ; }
        
        static void init_meta();
        
        double δa() const { return m_δ.a; }
        double δxy() const { return m_δ.xy; }

        virtual PostCPtr    clone(rebind_k, const Header&) const override;
        
    protected:
        RotateBy²Command(const RotateBy²Command&, const Header&);
        ~RotateBy²Command();
        
    private:
        Spinor2D const  m_δ;
        
        RotateBy²Command(const RotateBy²Command&) = delete;
        RotateBy²Command(RotateBy²Command&&) = delete;
        RotateBy²Command& operator=(const RotateBy²Command&) = delete;
        RotateBy²Command& operator=(RotateBy²Command&&) = delete;
    };
}
