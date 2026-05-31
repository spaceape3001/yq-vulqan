////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "AmbientLight.hpp"
#include <yq/tachyon/api/LightMetaWriter.hpp>

YQ_TACHYON_IMPLEMENT(yq::tachyon::AmbientLight)

namespace yq::tachyon {
    void AmbientLight::init_meta()
    {
        auto w = writer<AmbientLight>();
        w.description("Ambient/Global Light");
    }
    
    AmbientLight::AmbientLight()
    {
    }
    
    AmbientLight::~AmbientLight()
    {
    }
    
    void        AmbientLight::snap(LightSnap&sn) const 
    {
        Light::snap(sn);
        sn.type = LightType::Ambient;
    }
}
