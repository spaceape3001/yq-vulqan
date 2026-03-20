////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Physics.hpp>

namespace yq::tachyon {
    class NoPhysics : public Physics {
        YQ_TACHYON_DECLARE(NoPhysics, Physics)
    public:
    
        NoPhysics();
        ~NoPhysics();
        
        static void init_meta();
        
    protected:
        void        snap(PhysicsSnap&) const;
    private:
        Meter       m_scale = 1._cm;
    };
}
