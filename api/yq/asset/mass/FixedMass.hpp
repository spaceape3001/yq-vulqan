////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/entity/Mass.hpp>
#include <yq/units.hpp>

namespace yq::tachyon {
    class FixedMass : public Mass {
        YQ_TACHYON_DECLARE(FixedMass, Mass)
    public:
        
        struct Param : public Mass::Param {
            Kilogram        mass    = 1._kg;
        };
        
        FixedMass();
        FixedMass(const Param&);
        ~FixedMass();
        
        static void init_meta();
        
    protected:
        void    snap(MassSnap&) const;
        
        Kilogram        m_mass;
    };
}
