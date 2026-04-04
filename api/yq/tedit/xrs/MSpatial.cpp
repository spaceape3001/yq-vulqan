////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MSpatial.hpp"
#include "MTachyonMetaWriter.hpp"
#include <yq/tachyon/api/Spatial.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::MSpatial)

namespace yq::tachyon {
    MSpatial::MSpatial(TypedID tid) : MTachyon(tid)
    {
    }
    
    MSpatial::~MSpatial()
    {
    }
    
    void MSpatial::init_meta()
    {
        auto w = writer<MSpatial>();
        w.description("Spatial Qt Binder");
        w.manage<Spatial>();
    }
}


#include "moc_MSpatial.cpp"
