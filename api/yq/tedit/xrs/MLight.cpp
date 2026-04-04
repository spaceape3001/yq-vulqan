////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MLight.hpp"
#include "MTachyonMetaWriter.hpp"
#include <yq/tachyon/api/Light.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::MLight)

namespace yq::tachyon {
    MLight::MLight(TypedID tid) : MTachyon(tid)
    {
    }
    
    MLight::~MLight()
    {
    }
    
    void MLight::init_meta()
    {
        auto w = writer<MLight>();
        w.description("Light Qt Binder");
        w.manage<Light>();
    }
}


#include "moc_MLight.cpp"
