////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SimpleSpatial3.hpp"
#include <yq/tachyon/api/Spatial3MetaWriter.hpp>
#include <yq/tachyon/aspect/ASpatial3Writer.hxx>

YQ_TACHYON_IMPLEMENT(yq::tachyon::SimpleSpatial³)

namespace yq::tachyon {
    SimpleSpatial³::SimpleSpatial³(const Vector3D& pos, const Quaternion3D& ori, const Vector3D& scale, const Param& p) :
        Spatial³(p), ASpatial³(pos, ori, scale)
    {
    }

    SimpleSpatial³::~SimpleSpatial³()
    {
    }    

    void SimpleSpatial³::snap(Spatial³Snap& sn) const
    {
        Spatial³::snap(sn, m_position, m_orientation, m_scale);
    }

    void SimpleSpatial³::init_meta()
    {
        auto w = writer<SimpleSpatial³>();
        
        ASpatial³::init_meta(w);
        
        w.description("Simple Spatial in 3 dimensions");
    }
}
