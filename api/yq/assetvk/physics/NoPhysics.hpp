////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Physics.hpp>
#include <yq/tachyon/aspect/AScreenScaleM.hpp>

namespace yq::tachyon {
    class NoPhysics : public Physics, public AScreenScaleM {
        YQ_TACHYON_DECLARE(NoPhysics, Physics)
    public:
    
        NoPhysics();
        ~NoPhysics();
        
        static void init_meta();
        
    protected:
        void        snap(PhysicsSnap&) const;
    };
}

YQ_TACHYON_FORCE(yq::tachyon::NoPhysics)
