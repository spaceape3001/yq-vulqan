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
    
        ViSampler(ViDevice&, const Sampler&);
        ~ViSampler();
        
        VkSampler               sampler() const { return m_sampler; }
        bool                    valid() const { return static_cast<bool>(m_sampler); }

        void                    kill();
        const SamplerInfo&      info() const { return m_info; }
    
    private:
        ViDevice&           m_device;
        VkSampler           m_sampler   = nullptr;
        SamplerInfo         m_info      = {};

        std::error_code     _init(const Sampler&);
        void                _kill();
        void                _wipe();
    };
}
