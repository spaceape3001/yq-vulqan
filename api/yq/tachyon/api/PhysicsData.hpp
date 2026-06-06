////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/ModelData.hpp>
#include <yq/tachyon/typedef/physics.hpp>
//#include <yq/tachyon/function/FNGravity3M.hpp>
//#include <yq/tachyon/function/FNWind3M.hpp>

namespace yq::tachyon {
    //class Frame;
    struct PhysicsSnap : public ModelSnap {
        // this list will expand... all valid physics in use
    
    
        //! All gravitational sources (can be more than one.... :) )
        //std::vector<FNGravity³M>    gravity3;
        
        //! Simple wind (can be multiple sources, air medium assumed)
        //std::vector<FNWind³M>       wind3;
        
        PhysicsSnap();
        ~PhysicsSnap();
        
        //MeterPerSecond²3D           gravity(const Meter3D&) const;
        //MeterPerSecond3D            wind(const Meter3D&) const;
        
        //const PhysicsSnap*          parent(const Frame* frame=nullptr) const;
    };
    
    struct PhysicsData : public ModelData {
    };
}
