////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/api/ScreenScaleData.hpp>
#include <yq/tachyon/typedef/physics.hpp>
#include <yq/tachyon/function/FNGravity3M.hpp>
#include <yq/tachyon/function/FNScreenMapper2M.hpp>
#include <yq/tachyon/function/FNScreenMapper3M.hpp>
#include <yq/tachyon/function/FNScreenUnmapper2M.hpp>
#include <yq/tachyon/function/FNScreenUnmapper3M.hpp>
#include <yq/tachyon/function/FNWind3M.hpp>

namespace yq::tachyon {
    class Frame;
    struct PhysicsSnap : public TachyonSnap, public ScreenScaleSnap {
        // this list will expand... all valid physics in use
    
    
        //! All gravitational sources (can be more than one.... :) )
        std::vector<FNGravity³M>    gravity3;
        
        //! Simple wind (can be multiple sources, air medium assumed)
        std::vector<FNWind³M>       wind3;
        
        PhysicsSnap();
        ~PhysicsSnap();
        
        MeterPerSecond²3D           gravity(const Meter3D&) const;
        MeterPerSecond3D            wind(const Meter3D&) const;
        
        //! \note Will return NAN when mapping is undefined
        Vector3D                    map(const Meter3D&, const Frame* frame=nullptr) const;
        //! \note Will return NAN when mapping is undefined
        Vector2D                    map(const Meter2D&, const Frame* frame=nullptr) const;
        
        //! \note Will return NAN when unmapping is undefined
        Meter2D                     unmap(const Vector2D&, const Frame* frame=nullptr) const;

        //! \note Will return NAN when unmapping is undefined
        Meter3D                     unmap(const Vector3D&, const Frame* frame=nullptr) const;
        
        const PhysicsSnap*          parent(const Frame* frame=nullptr) const;
    };
    
    struct PhysicsData : public TachyonData {
    };
}
