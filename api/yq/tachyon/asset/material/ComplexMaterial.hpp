////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/math/UVW.hpp>
#include <yq/color/RGBA.hpp>
#include <yq/tachyon/typedef/material.hpp>
#include <yq/tachyon/typedef/texture.hpp>
#include <yq/resource/Resource.hpp>

/*
    Holding point for the non-basic materials (it was getting *VERY* complicated)
*/

namespace yq::tachyon {

    enum class MaterialBit {
        Ambient,
        Diffuse,
        Specular
    };

    //  End mapping for the texture type?  (Comes from tinyobj)
    enum class MaterialTexType {
        None    = 0,
        Sphere,
        CubeTop,
        CubeBottom,
        CubeFront,
        CubeBack,
        CubeLeft,
        CubeRight
    };
    
    //! Slate is the aspect to a material, be it the regular color, roughness, emissions, etc
    struct MaterialSlate {
        TextureCPtr         texture;
        float               sharpness           = 1.0;
        float               brightness          = 1.0;
        float               contrast            = 1.;
        UVW3F               origin_offset       = { 0., 0., 0. };
        UVW3F               scale               = { 1., 1., 1. };
        UVW3F               turbulence          = { 0., 0., 0. };
        int                 texture_resolution  = 1;
        
        bool                clamp               = false;
        char                imfchan             = '\0';
        UVW<bool>           blend               = { true, true, true };
        float               bump_multiplier     = 1.0;
        MaterialTexType     tex_type            = MaterialTexType::None;
        std::string         color_space;
        
        //RGBA4F              scale               = { 1., 1., 1., 1. };
        //RGBA4F              base                = { 0., 0., 0., 0. };
        
        MaterialSlate();
        MaterialSlate(const MaterialSlate&);
        MaterialSlate(MaterialSlate&&);
        MaterialSlate& operator=(const MaterialSlate&);
        MaterialSlate& operator=(MaterialSlate&&);
        ~MaterialSlate();
    };

    /*! "Material" specification (file)
        
        This is a material specification, can be used for 
        shapes.  Merging wavefront Obj & GLTF specifications into
        a singular spec.
    */
    class Material : public Resource {
        YQ_RESOURCE_DECLARE(Material, Resource)
    public:
        // TODO (Contents)
        
        RGBA4F              color        = { 0., 0., 0., 0. };
        TextureCPtr         texture;
        
    
        std::map<MaterialBit,MaterialSlate> slates;

        bool                double_sided = false;
        RGB3D               emmisive_factor{0., 0., 0.};
        std::vector<int>    lods;
    
        Material();
        ~Material();
        static void init_meta();
    };
}
