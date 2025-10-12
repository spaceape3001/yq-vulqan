////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "LightSpec.hpp"
#include <yq/resource/ResourceMetaWriter.hpp>

namespace yq::tachyon {
    LightSpec::LightSpec()
    {
    }
    
    LightSpec::~LightSpec()
    {
    }
    
    void LightSpec::init_meta()
    {
        auto w = writer<LightSpec>();
    }
}

YQ_RESOURCE_IMPLEMENT(yq::tachyon::LightSpec)
