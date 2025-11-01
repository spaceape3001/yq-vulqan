////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/typedef/sampler.hpp>
#include <yq/resource/Resource.hpp>
#include <yq/tachyon/asset/SamplerInfo.hpp>

namespace yq::tachyon {
    class Sampler : public Resource {
        YQ_RESOURCE_DECLARE(Sampler, Resource)
    public:

        static SamplerCPtr                    simple();
        
        const SamplerInfo   info;
        
        Sampler(const SamplerInfo&);
        
        virtual size_t                  data_size() const override { return 0ULL; }
        
        static void init_meta();
    
    private:
        ~Sampler();
    };
}
