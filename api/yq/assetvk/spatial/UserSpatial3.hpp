////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Spatial3.hpp>
#include <yq/tachyon/interface/IOrientation3.hpp>
#include <yq/tachyon/interface/IPosition3.hpp>
#include <yq/tensor/Tensor33.hpp>
#include <yq/userexpr/Algebra.hpp>
#include <yq/userexpr/UserExpr.hpp>
#include <yq/vector/Quaternion3.hpp>
#include <yq/vector/Vector3.hpp>

namespace yq::tachyon {
    struct UserSpatial³Snap;
    class User³HCommand;
    class User³PCommand;
    class User³RCommand;
    class User³XCommand;
    class User³YCommand;
    class User³ZCommand;
    
    class UserSpatial³ : public Spatial³, public IPosition³, public IOrientation³ {
        YQ_TACHYON_SNAP(UserSpatial³Snap)
        YQ_TACHYON_DECLARE(UserSpatial³, Spatial³);
    public:
        
        struct Param : public Spatial³::Param {
            Algebra     h, p, r;
            Algebra     x, y, z;
        };
        
        UserSpatial³();
        UserSpatial³(const Param&);
        ~UserSpatial³();
        
        Vector3D        position() const;
        Quaternion3D    orientation() const;
        
        Execution       tick(const Context&) override;
        
        static void init_meta();
        
    protected:
        void    snap(UserSpatial³Snap&) const;
        
    private:
        struct Value {
            Algebra         algebra;
            UserExpr        userexpr;
            double          value       = 0.;
            
            Value& operator=(const Algebra&);
            void    tick(expr::Context&);
            Value();
            ~Value();
        }   m_h, m_r, m_p, m_x, m_y, m_z;
        
        Vector3D        m_position      = ZERO;
        Quaternion3D    m_orientation   = IDENTITY;
        
        const Algebra& h() const { return m_h.algebra; }
        const Algebra& p() const { return m_p.algebra; }
        const Algebra& r() const { return m_r.algebra; }
        const Algebra& x() const { return m_x.algebra; }
        const Algebra& y() const { return m_y.algebra; }
        const Algebra& z() const { return m_z.algebra; }
        
        void    set_h(const Algebra&);
        void    set_p(const Algebra&);
        void    set_r(const Algebra&);
        void    set_x(const Algebra&);
        void    set_y(const Algebra&);
        void    set_z(const Algebra&);
        
        void on_h_command(const User³HCommand&);
        void on_p_command(const User³PCommand&);
        void on_r_command(const User³RCommand&);
        void on_x_command(const User³XCommand&);
        void on_y_command(const User³YCommand&);
        void on_z_command(const User³ZCommand&);
    };

}
