////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Material.hpp"
#include <yq/resource/ResourceMetaWriter.hpp>
#include <yq/tachyon/asset/Texture.hpp>

namespace yq::tachyon {
    Material::Material()
    {
    }
    
    Material::~Material()
    {
    }
    
    void Material::init_meta()
    {
        auto w = writer<Material>();
        w.description("Material");
    }
}

YQ_RESOURCE_IMPLEMENT(yq::tachyon::Material)
