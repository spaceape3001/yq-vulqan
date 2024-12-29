////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Spatial³.hpp>
#include <yq/math/SimpleSpace.hpp>

namespace yq::tachyon {
    class SimpleSpatial³ : public Spatial³ {
        YQ_OBJECT_DECLARE(SimpleSpatial³, Spatial³);
    public:
    
        struct Param {
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

        virtual Tensor44D       local2parent() const override;
        virtual Tensor44D       parent2local() const override;

        static void init_info();

    private:
        SimpleSpace     m_space;
    };
}
