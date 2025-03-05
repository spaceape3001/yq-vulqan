////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/typedef/sampler.hpp>
#include <yq/core/Ref.hpp>
#include <vulkan/vulkan_core.h>
#include <yt/gfx/SamplerInfo.hpp>
#include <system_error>

namespace yq::tachyon {
    class ViDevice;
    
    class ViSampler : public RefCount {
    public:
    
        static VkSamplerCreateInfo  vkInfo(ViDevice&, const SamplerInfo&);
    
        ViSampler();
        ViSampler(ViDevice&, const Sampler&);
        ~ViSampler();
        
        bool                    consistent() const;
        VkSampler               sampler() const { return m_sampler; }
        bool                    valid() const;

        std::error_code         init(ViDevice&, const Sampler&);
        void                    kill();
        const SamplerInfo&      info() const { return m_info; }
    
    private:
        VkDevice            m_device       = nullptr;
        VkSampler           m_sampler   = nullptr;
        SamplerInfo         m_info      = {};

        std::error_code     _init(ViDevice&, const Sampler&);
        void                _kill();
        void                _wipe();
    };
}
