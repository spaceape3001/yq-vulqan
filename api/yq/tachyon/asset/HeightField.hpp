////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Ref.hpp>
#include <yq/core/UniqueID.hpp>
#include <yq/resource/Resource.hpp>
#include <yq/tachyon/asset/TextureInfo.hpp>
#include <yq/tachyon/typedef/raster.hpp>
#include <yq/tachyon/typedef/sampler.hpp>
#include <yq/tachyon/typedef/height_field.hpp>
#include <optional>

//  temporary... if we ever move to a dedicated height field (might have a height field -> raster or something later)
#include <yq/tachyon/asset/Texture.hpp>

namespace yq::tachyon {
    HeightFieldCPtr         load_heightfield(const Url&);
    std::pair<float,float>  minmax_elevation(const HeightField&);

#if 0

    /*! HeightField (as image & view/sampler info)
        
        It's basically a texture, but more limited in scope.  
        
        Conventions to channels (if present):
        
        red     = value
        green   = dvalue/du
        blue    = dvalue/dv
        alpha   = d^2 value/duv
    */
    class HeightField : public Resource {
        YQ_RESOURCE_DECLARE(HeightField, Resource)
    public:
    
        struct LoHi {
            double      lo  = 0.;
            double      hi  = 0.;
        };
    
        /*! The gridded Data(s)
        */
        RasterCPtr          gridded;

        // Should match dimensions in gridded.sizes...  If empty, default is [0,1] on each dimension
        LoHi                x, y;

        //! Sampler info
        SamplerCPtr         sampler;
        
        //! View information
        TextureInfo         info;

        static HeightFieldCPtr  load(std::string_view);
        static HeightFieldCPtr  load(std::string_view, const TextureInfo& texInfo);
        static HeightFieldCPtr  load(std::string_view, const TextureInfo2& texInfo);
        static HeightFieldCPtr  load(std::string_view, const SamplerCPtr& _sampler, const TextureInfo& texInfo = {});

        HeightField();
        HeightField(RasterCPtr);
        HeightField(RasterCPtr, const SamplerCPtr& _sampler, const TextureInfo& texInfo={});
        HeightField(RasterCPtr, const TextureInfo& texInfo);
        HeightField(RasterCPtr, const TextureInfo2& texInfo);
        
        static void init_meta();
        virtual size_t      data_size() const override { return 0; }
        
    private:
        ~HeightField();
    };
#endif
}

