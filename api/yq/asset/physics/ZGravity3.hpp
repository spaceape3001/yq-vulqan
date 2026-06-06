////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <yq/tachyon/physics/Acceleration3.hpp>
#include <yq/tachyon/physics/Acceleration3Data.hpp>

namespace yq::tachyon {
    struct ZGravity³Snap : public Acceleration³Snap {
        MeterPerSecond² gravity{};
    };
    
    class ZGravity³ : public Acceleration³ {
        YQ_TACHYON_SNAP(ZGravity³Snap)
        YQ_TACHYON_DECLARE(ZGravity³, Acceleration³)
    public:
        
        static constexpr const MeterPerSecond² kDefGravity{9.81};
    
        struct Param : public Acceleration³::Param {
            MeterPerSecond²     gravity = kDefGravity;
        };
    
        ZGravity³();
        ZGravity³(const Param&);
        ~ZGravity³();
    
        static void init_meta();
    protected:
        void    snap(ZGravity³Snap& sn) const;
    
    private:
        MeterPerSecond²     m_gravity;
    };
    
}
