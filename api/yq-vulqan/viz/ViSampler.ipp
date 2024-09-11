////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViSampler.hpp"

#include <yq-vulqan/errors.hpp>
#include <yq-vulqan/logging.hpp>
#include <yq-vulqan/sampler/Sampler.hpp>
#include <yq-vulqan/v/VqStructs.hpp>
#include <yq-vulqan/viz/ViVisualizer.hpp>

namespace yq::tachyon {
    VkSamplerCreateInfo  ViSampler::vkInfo(ViVisualizer& viz, const SamplerInfo& sami)
    {
        VqSamplerCreateInfo     ret;
        ret.flags                   = (VkSamplerCreateFlags) sami.flags.value();
        ret.magFilter               = (VkFilter) sami.magFilter.value();
        ret.minFilter               = (VkFilter) sami.minFilter.value();
        ret.mipmapMode              = (VkSamplerMipmapMode) sami.mipmapMode.value();
        ret.addressModeU            = (VkSamplerAddressMode) sami.addressMode.u.value();
        ret.addressModeV            = (VkSamplerAddressMode) sami.addressMode.v.value();
        ret.addressModeW            = (VkSamplerAddressMode) sami.addressMode.w.value();
        ret.mipLodBias              = sami.mipLodBias;
        ret.anisotropyEnable        = sami.anisotropyEnable ? *sami.anisotropyEnable : VK_TRUE;
        ret.maxAnisotropy           = sami.maxAnisotropy ? *sami.maxAnisotropy : viz.max_sampler_anisotropy();
        ret.compareEnable           = sami.compareEnable ? VK_TRUE : VK_FALSE;
        ret.compareOp               = (VkCompareOp) sami.compareOp.value();
        ret.minLod                  = sami.minLod;
        ret.maxLod                  = sami.maxLod;
        ret.borderColor             = (VkBorderColor) sami.borderColor.value();
        ret.unnormalizedCoordinates = sami.unnormalizedCoordinates ? VK_TRUE : VK_FALSE;
        return ret;
    }

    ViSampler::ViSampler()
    {
    }
    
    ViSampler::ViSampler(ViVisualizer& viz, const Sampler& sam)
    {
        if(viz.device()){
            std::error_code ec  = _init(viz, sam);
            if(ec != std::error_code()){
                vqWarning << "unable to create a sampler: " << ec.message();
                _wipe();
            }
        }
    }
    
    ViSampler::~ViSampler()
    {
    }

    std::error_code     ViSampler::_init(ViVisualizer&viz, const Sampler&sam)
    {
        VkSamplerCreateInfo sci  = vkInfo(viz, sam.info);
        if(vkCreateSampler(viz.device(), &sci, nullptr, &m_sampler) != VK_SUCCESS)
            return errors::sampler_cant_create();
            
        m_viz   = &viz;
        m_info  = sam.info;
        return {};
    }
    
    void                ViSampler::_kill()
    {
        if(m_sampler){
            vkDestroySampler(m_viz->device(), m_sampler, nullptr);
            m_sampler   = nullptr;
        }
    }
    
    void                ViSampler::_wipe()
    {
        m_viz       = nullptr;
        m_sampler   = nullptr;
        m_info      = {};
    }
    
    bool                ViSampler::consistent() const
    {
        return m_viz ? (m_sampler && m_viz->device()) : !m_sampler;
    }
    
    std::error_code     ViSampler::init(ViVisualizer& viz, const Sampler& sam)
    {
        if(m_viz){
            if(!consistent()){
                return errors::sampler_bad_state();
            }
            return errors::sampler_existing();
        }
        
        std::error_code ec  = _init(viz, sam);
        if(ec != std::error_code()){
            _wipe();
        }
        return ec;
    }
    
    void                ViSampler::kill()
    {
        if(valid()){
            _kill();
        }
        _wipe();
    }
    
    bool                ViSampler::valid() const
    {
        return m_viz && m_sampler && m_viz->device();
    }
}
