////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/typedef/sampler.hpp>
#include <yq/asset/Asset.hpp>
#include <yq/tachyon/SamplerInfo.hpp>

namespace yq::tachyon {
    class Sampler : public Asset {
        YQ_OBJECT_DECLARE(Sampler, Asset)
    public:

        //! Cache of images
        static TypedAssetFactory<Sampler>&    cache();
        
        static SamplerCPtr                      simple();
        
        //! Loads an image by key
        static const Sampler*                 load(std::string_view);
        
        const SamplerInfo   info;
        
        Sampler(const SamplerInfo&);
        
        virtual size_t                  data_size() const override { return 0ULL; }
    
    private:
        AssetFactory&       factory() const override;

        ~Sampler();
    };
}
