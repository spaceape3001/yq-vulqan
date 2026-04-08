////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MSpatial3.hpp"
#include "MTachyonMetaWriter.hpp"
#include <yq/tachyon/api/Spatial3.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::MSpatial3)

namespace yq::tachyon {
    MSpatial3::MSpatial3(TypedID tid) : MSpatial(tid)
    {
    }
    
    MSpatial3::~MSpatial3()
    {
    }
    
    void MSpatial3::init_meta()
    {
        auto w = writer<MSpatial3>();
        w.description("Spatial³ Qt Binder");
        w.manage<Spatial³>();
    }
}


#include "moc_MSpatial3.cpp"
