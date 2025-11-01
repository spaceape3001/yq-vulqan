////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/api/Interface.hpp>

namespace yq::tachyon {
    class PNearPlane;
    
    class INearPlane {
    public:
        YQ_INTERFACE_DECLARE(INearPlane, PNearPlane)
    
        virtual double  near_plane() const = 0;

        virtual bool    near_plane(disabled_k) const { return false; }
        virtual bool    near_plane(settable_k) const { return false; }
        
        virtual void    near_plane(set_k, double){}
        
        INearPlane();
        virtual ~INearPlane();
        
        static void init_meta();
    };
}
