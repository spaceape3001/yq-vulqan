////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/model/Physics.hpp>

namespace yq::tachyon {
    class NoPhysics : public Physics {
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
