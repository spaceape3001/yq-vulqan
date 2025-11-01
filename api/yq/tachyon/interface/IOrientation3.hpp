////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/unit/declare.hpp>
#include <yq/unit/MKS.hpp>
#include <yq/vector/Quaternion3.hpp>
#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/api/Interface.hpp>

namespace yq::tachyon {
    class POrientation³;

    class IOrientation³ {
        YQ_INTERFACE_DECLARE(IOrientation³, POrientation³)
    public:
    
        virtual Quaternion3D    orientation() const = 0;
        virtual bool            orientation(disabled_k) const { return false; }
        virtual bool            orientation(settable_k) const { return false; }
        virtual bool            orientation(rotatable_k) const { return false; }
        
        virtual void            orientation(set_k, const Quaternion3D&){}
        virtual void            orientation(set_k, hpr_k, Radian, Radian, Radian){}
        virtual void            orientation(set_k, heading_k, Radian){}
        virtual void            orientation(set_k, pitch_k, Radian){}
        virtual void            orientation(set_k, roll_k, Radian){}
        
        virtual void            orientation(rotate_k, const Quaternion3D&){}
        virtual void            orientation(rotate_k, const unit::Radian3D&){}
        
        virtual void            orientation(rotate_k, pitch_k, Radian){}
        virtual void            orientation(rotate_k, roll_k, Radian){}
        virtual void            orientation(rotate_k, yaw_k, Radian){}

        static void init_meta();
    };
}
