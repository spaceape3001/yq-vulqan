////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-vulqan/typedef/sampler.hpp>
#include <yq-vulqan/asset/Asset.hpp>
#include <yq-vulqan/sampler/SamplerInfo.hpp>

namespace yq::tachyon {
    template <typename> class TypedAssetFactory;

    class Sampler : public Asset {
        YQ_OBJECT_DECLARE(Sampler, Asset)
    public:
    
        //! Cache of images
        static TypedAssetFactory<Sampler>&    cache();
        
        //! Loads an image by key
        static const Sampler*                 load(std::string_view);
        
        const SamplerInfo   info;
        
        Sampler(const SamplerInfo&);
    
    private:
        ~Sampler();
    };
}
