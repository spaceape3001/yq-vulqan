////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/resource/ResourceMetaWriter.hpp>
#include <tachyon/resource/Sampler.hpp>

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

YQ_OBJECT_IMPLEMENT(yq::tachyon::Sampler)
