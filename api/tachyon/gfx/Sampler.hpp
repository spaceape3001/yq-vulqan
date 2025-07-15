////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/typedef/sampler.hpp>
#include <yq/asset/Asset.hpp>
#include <tachyon/gfx/SamplerInfo.hpp>

namespace yq::tachyon {
    class Sampler : public Asset {
        YQ_ASSET_DECLARE(Sampler, Asset)
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
