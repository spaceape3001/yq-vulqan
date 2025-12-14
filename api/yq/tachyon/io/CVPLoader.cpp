////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "CVPLoader.hpp"
#include <yq/core/DelayInit.hpp>
#include <yq/resource/ResourceDriverAPI.hpp>
#include <yq/tachyon/asset/Texture.hpp>
#include <yq/tachyon/asset/Raster.hpp>
#include <yq/tachyon/asset/Sampler.hpp>
#include <yq/resource/Resource.hxx>
#include <fstream>

namespace yq::tachyon {
    TexturePtr       loadCVP(const std::filesystem::path& fpath)
    {
        std::ifstream   fin(fpath);
        if(!fin.good())
            return {};
        return loadCVP(fin, to_url(fpath));
    }
    
    static constexpr TextureInfo2 makeTexInfo()
    {
        TextureInfo2    ret;
        ret.addressMode     = SamplerAddressModeUVW(ALL, SamplerAddressMode::ClampToEdge);
        return ret;
    }
    
    TexturePtr       loadCVP(std::istream& istr, const Url& url)
    {
        static constexpr const size_t   kBufferSize     = 256;
        static const TextureInfo2       kTextureInfo    = makeTexInfo();
        char                            buffer[kBufferSize];
        std::vector<RGBA4F>             data;
        
        memset(buffer, 0, kBufferSize);
        while(!istr.eof()){
            buffer[0] = '\0';   // safety
            istr.getline(buffer, kBufferSize);
            auto x  = to_rgba4f(buffer);
            if(!x)
                continue;
            data.push_back(*x);
        }
        
        if(data.size() < 2)
            return {};
        
        RasterInfo  rasInfo;
        rasInfo.size    = { (uint32_t) data.size(), 1, 1, 1 };
        rasInfo.format  = DataFormat::R32G32B32A32_SFLOAT;
        rasInfo.type    = RasterType::Is1D;
        RasterPtr   ras = new Raster(rasInfo, Memory(COPY, data));
        return new Texture(ras, kTextureInfo);
    }
    
}

namespace {
    using namespace yq;
    using namespace yq::tachyon;

    TexturePtr   loadCVP_driver(std::istream& istr, const ResourceLoadAPI&api)
    {
        return loadCVP(istr, api.url());
    }

    void    reg_imageCVP()
    {
        Texture::IO::add_loader({.extensions={"cvp"}}, loadCVP_driver);
    }
    
    YQ_INVOKE(reg_imageCVP();)
}
