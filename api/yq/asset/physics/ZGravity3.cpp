////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ZGravity3.hpp"
#include <yq/tachyon/model/Acceleration3MetaWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::ZGravity³)

namespace yq::tachyon {
    ZGravity³::ZGravity³() : ZGravity³(Param())
    {
    }

    ZGravity³::ZGravity³(const Param&p) : Acceleration³(p), m_gravity(p.gravity)
    {
    }
    
    ZGravity³::~ZGravity³()
    {
    }

    void    ZGravity³::snap(ZGravity³Snap& sn) const
    {
        Acceleration³::snap(sn);
        sn.gravity  = m_gravity;
        sn.acceleration = [g=m_gravity](Entity³ID) -> MeterPerSecond²3D{
            return { 0., 0., g };
        };
    }
    
    void ZGravity³::init_meta()
    {
        auto w = writer<ZGravity³>();
        w.description("Standard Z gravity");
    }
}

