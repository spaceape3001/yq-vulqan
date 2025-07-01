////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/asset/AssetFactory.hpp>
#include <yq/asset/AssetMetaWriter.hpp>
#include <tachyon/gfx/Sampler.hpp>

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

    SamplerCPtr    Sampler::simple()
    {
        static SamplerCPtr  s_ret   = new Sampler(SamplerInfo());
        return s_ret;
    }
    
    Sampler::Sampler(const SamplerInfo& samplerInfo) : info(samplerInfo) 
    {
    }

    Sampler::~Sampler()
    {
    }

    AssetFactory&       Sampler::factory() const 
    {
        return cache();
    }

    void    Sampler::init_meta()
    {
        auto w = writer<Sampler>();
        w.description("Sampler Asset");
        w.options({Meta::Flag::SAMPLER});
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::Sampler)
