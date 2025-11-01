////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/asset/Sampler.hpp>
#include <yq/resource/ResourceMetaWriter.hpp>

namespace yq::tachyon {
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

    void    Sampler::init_meta()
    {
        auto w = writer<Sampler>();
        w.description("Sampler Resource");
        w.options({Meta::Flag::SAMPLER});
    }
}

YQ_RESOURCE_IMPLEMENT(yq::tachyon::Sampler)
