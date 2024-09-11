////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Sampler.hpp"

#include <yq-vulqan/asset/AssetFactory.hpp>
#include <yq-vulqan/asset/AssetInfoWriter.hpp>

namespace yq::tachyon {
    TypedAssetFactory<Sampler>&   Sampler::cache()
    {
        static TypedAssetFactory<Sampler>   s_ret;
        return s_ret;
    }
    
    const Sampler*  Sampler::load(std::string_view pp)
    {
        return cache().load(pp);
    }
    
    Sampler::Sampler(const SamplerInfo& samplerInfo) : info(samplerInfo) 
    {
    }

    Sampler::~Sampler()
    {
    }

    static void    reg_sampler()
    {
        auto w = writer<Sampler>();
        w.description("Sampler Asset");
        w.options({Meta::Flag::SAMPLER});
    }

    YQ_INVOKE(reg_sampler();)
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::Sampler)
