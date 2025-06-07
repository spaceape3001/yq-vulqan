////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/interface/IOrientation2.hpp>
#include <tachyon/api/Tachyon.hpp>

namespace yq::tachyon {

    class RotateBy²Command;
    class SetHeadingCommand;
    class SetOrientation²Command;
    class YawByCommand;

    class AOrientation² : public IOrientation², public virtual Tachyon::Helper {
    public:
    
        //!  Basic orientation in the 3D space
        Spinor2D        orientation() const override { return m_orientation; }

        double          orientation(a_k) const { return m_orientation.a; }
        double          orientation(xy_k) const { return m_orientation.xy; }
        
        //!  Set orientation the orientation (OVERRIDE THIS TO INTERCEPT/REJECT)
        virtual void    orientation(set_k, const Spinor2D&) override;

        void            orientation(set_k, heading_k, Radian) override;
        
        void            orientation(rotate_k, const Spinor2D&) override;
        void            orientation(rotate_k, Radian) override;
        void            orientation(rotate_k, yaw_k, Radian) override;
        
        virtual bool    orientation(disabled_k) const override { return false; }
        virtual bool    orientation(settable_k) const override { return true; }
        virtual bool    orientation(rotatable_k) const override { return true; }

        const Spinor2D& orientation(ref_k) const { return m_orientation; }

    protected:
        
        Spinor2D    m_orientation = IDENTITY;

        template <typename C>
        static void init_info(TachyonInfo::Writer<C>&);
        
        AOrientation²();
        virtual ~AOrientation²();
        
        void        orientation(emit_k);

    private:
        void on_rotate_by(const RotateBy²Command&);
        void on_set_heading(const SetHeadingCommand&);
        void on_set_orientation²(const SetOrientation²Command&);
        void on_yaw_by(const YawByCommand&);
    };
}
