////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/unit/declare.hpp>
#include <yq/unit/MKS.hpp>
#include <yq/vector/Spinor2.hpp>
#include <tachyon/keywords.hpp>
#include <tachyon/api/Interface.hpp>

namespace yq::tachyon {
    class POrientation²;

    class IOrientation² {
        YQ_INTERFACE_DECLARE(IOrientation², POrientation²)
    public:
    
        virtual Spinor2D        orientation() const = 0;
        virtual bool            orientation(disabled_k) const { return false; }
        virtual bool            orientation(settable_k) const { return false; }
        virtual bool            orientation(rotatable_k) const { return false; }
        
        virtual void            orientation(set_k, const Spinor2D&){}
        virtual void            orientation(set_k, heading_k, Radian){}
        
        virtual void            orientation(rotate_k, const Spinor2D&){}
        virtual void            orientation(rotate_k, Radian){}

        virtual void            orientation(rotate_k, yaw_k, Radian){}

        static void init_info();
    };
}
