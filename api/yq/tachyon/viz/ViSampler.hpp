////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/typedef/sampler.hpp>
#include <yq/core/Ref.hpp>
#include <vulkan/vulkan_core.h>
#include <yq/tachyon/api/SamplerInfo.hpp>
#include <system_error>

namespace yq::tachyon {
    class ViVisualizer;
    
    class ViSampler : public RefCount {
    public:
    
        static VkSamplerCreateInfo  vkInfo(ViVisualizer&, const SamplerInfo&);
    
        ViSampler();
        ViSampler(ViVisualizer&, const Sampler&);
        ~ViSampler();
        
        bool                    consistent() const;
        VkSampler               sampler() const { return m_sampler; }
        bool                    valid() const;
        ViVisualizer*           visualizer() const { return m_viz; }

        std::error_code         init(ViVisualizer&, const Sampler&);
        void                    kill();
        const SamplerInfo&      info() const { return m_info; }
    
    private:
        ViVisualizer*       m_viz       = nullptr;
        VkSampler           m_sampler   = nullptr;
        SamplerInfo         m_info      = {};

        std::error_code     _init(ViVisualizer&, const Sampler&);
        void                _kill();
        void                _wipe();
    };
}
