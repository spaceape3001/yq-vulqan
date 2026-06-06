////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "FixedMass.hpp"
#include <yq/tachyon/entity/MassMetaWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::FixedMass)

namespace yq::tachyon {
    FixedMass::FixedMass() : FixedMass(Param()) 
    {
    }
    
    FixedMass::FixedMass(const Param& p) : Mass(p), m_mass(p.mass)
    {
    }
    
    FixedMass::~FixedMass()
    {
    }
        
    void    FixedMass::snap(MassSnap&sn) const
    {
        Mass::snap(sn);
        sn.mass = m_mass;
    }

    void FixedMass::init_meta()
    {
        auto w = writer<FixedMass>();
        w.description("Fixed Mass");
        w.property("mass", &FixedMass::m_mass);
    }
}
