////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "BasicMaterial.hpp"
#include <yq/color/colors.hpp>
#include <yq/resource/ResourceMetaWriter.hpp>

YQ_RESOURCE_IMPLEMENT(yq::tachyon::BasicMaterial)

namespace yq::tachyon {
    BasicMaterial::BasicMaterial(color_t v) : color(rgba4f(v))
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
    }
}
