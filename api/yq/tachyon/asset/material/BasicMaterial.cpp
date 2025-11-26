////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "BasicMaterial.hpp"
#include <yq/color/colors.hpp>
#include <yq/tachyon/asset/MaterialMetaWriter.hpp>

YQ_RESOURCE_IMPLEMENT(yq::tachyon::BasicMaterial)

namespace yq::tachyon {
    BasicMaterial::BasicMaterial(const color_t& v) : color(rgba4f(v))
    {
    }
    
    BasicMaterial::BasicMaterial() : BasicMaterial(color::White) 
    {
    }
    
    BasicMaterial::~BasicMaterial()
    {
    }

    void BasicMaterial::init_meta()
    {
        auto w = writer<BasicMaterial>();
        w.description("Basic Simple Material (color)");
        w.property("color", &BasicMaterial::color);
        w.property("roughness", &BasicMaterial::roughness);
        w.property("metallic", &BasicMaterial::metallic);
    }
}
