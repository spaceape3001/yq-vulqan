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

    MaterialSlate::MaterialSlate() = default;
    MaterialSlate::MaterialSlate(const MaterialSlate&) = default;
    MaterialSlate::MaterialSlate(MaterialSlate&&) = default;
    MaterialSlate& MaterialSlate::operator=(const MaterialSlate&) = default;
    MaterialSlate& MaterialSlate::operator=(MaterialSlate&&) = default;
    MaterialSlate::~MaterialSlate() = default;
}

YQ_RESOURCE_IMPLEMENT(yq::tachyon::Material)
