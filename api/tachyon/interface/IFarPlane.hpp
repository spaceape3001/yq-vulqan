////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/keywords.hpp>
#include <tachyon/api/Interface.hpp>

namespace yq::tachyon {
    class PFarPlane;
    
    class IFarPlane {
    public:
        YQ_INTERFACE_DECLARE(IFarPlane, PFarPlane)
    
        virtual double  far_plane() const = 0;

        virtual bool    far_plane(disabled_k) const { return false; }
        virtual bool    far_plane(settable_k) const { return false; }
        
        virtual void    far_plane(set_k, double){}
        
        IFarPlane();
        virtual ~IFarPlane();
        
        static void init_meta();
    };
}
