////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "MaterialSpec.hpp"
#include <yq/resource/ResourceMetaWriter.hpp>

namespace yq::tachyon {
    MaterialSpec::MaterialSpec()
    {
    }
    
    MaterialSpec::~MaterialSpec()
    {
    }
    
    void MaterialSpec::init_meta()
    {
        auto w = writer<MaterialSpec>();
        w.description("Material Specification");
    }
}

YQ_RESOURCE_IMPLEMENT(yq::tachyon::MaterialSpec)
