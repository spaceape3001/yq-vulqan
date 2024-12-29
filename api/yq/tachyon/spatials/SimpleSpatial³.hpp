////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Spatial³.hpp>
#include <yq/tachyon/interfaces/IPosition³.hpp>
#include <yq/math/SimpleSpace.hpp>

namespace yq::tachyon {
    class SimpleSpatial³ : public Spatial³, private IPosition³ {
        YQ_TACHYON_DECLARE(SimpleSpatial³, Spatial³);
    public:
    
        struct Param : public Spatial³::Param {
            Vector3D        position        = ZERO;
            Quaternion3D    orientation     = IDENTITY;
            Vector3D        scale           = ONE;
            
            Param(){}
        };
    
        SimpleSpatial³(const Param&p = Param());
        ~SimpleSpatial³();
        
        void    move_by(const Vector3D&);
        void    rotate_by(const Quaternion3D&);
        void    rotate_by(const unit::Radian3D&);
        void    inflate_by(const Vector3D&);

        void    set_position(const Vector3D&);
        void    set_orientation(const Quaternion3D&);
        void    set_scale(const Vector3D&);


        //!  Basic position in the 3D space
        virtual Vector3D    position() const override;
        
        //!  Set position the position
        virtual void        position(set_k, const Vector3D&) override;
        
        virtual void        position(set_k, x_k, double) override;
        virtual void        position(set_k, y_k, double) override;
        virtual void        position(set_k, z_k, double) override;
        
        //!  Move the position (ie set to position + delta)
        virtual void        position(move_k, const Vector3D&Δ) override;

        virtual void        position(move_k, x_k, double Δx) override;
        virtual void        position(move_k, y_k, double Δy) override;
        virtual void        position(move_k, z_k, double Δz) override;

        virtual bool        position(disabled_k) const override { return false; }
        virtual bool        position(settable_k) const override { return true; }
        virtual bool        position(moveable_k) const override { return true; }


        static void init_info();
        

    protected:
        
        void        snap(Spatial³Snap&) const;

    private:
        Vector3D        m_position        = ZERO;
        Quaternion3D    m_orientation     = IDENTITY;
        Vector3D        m_scale           = ONE;
    };
}
