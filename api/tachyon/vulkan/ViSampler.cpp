////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <tachyon/vulkan/ViSampler.hpp>

#include <yt/errors.hpp>
#include <yt/logging.hpp>
#include <tachyon/gfx/Sampler.hpp>
#include <tachyon/vulkan/VqStructs.hpp>
#include <tachyon/vulkan/ViDevice.hpp>

#include <tachyon/vulkan/ViLogging.hpp>

namespace yq::tachyon {
    namespace errors {
        using sampler_bad_state                 = error_db::entry<"Sampler is in a bad state">;
        using sampler_cant_create               = error_db::entry<"Unable to create vulkan sampler">;
        using sampler_existing                  = error_db::entry<"Sampler already created">;
    }

    VkSamplerCreateInfo  ViSampler::vkInfo(ViDevice& viz, const SamplerInfo& sami)
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

    ViSampler::ViSampler(ViDevice& viz, const Sampler& sam) : m_device(viz)
    {
        std::error_code ec  = _init(sam);
        if(ec != std::error_code()){
            vizWarning << "unable to create a sampler: " << ec.message();
            _wipe();
        }
    }
    
    ViSampler::~ViSampler()
    {
        kill();
    }

    std::error_code     ViSampler::_init(const Sampler&sam)
    {
        VkSamplerCreateInfo sci = vkInfo(m_device, sam.info);
        
        VkResult res = vkCreateSampler(m_device.device(), &sci, nullptr, &m_sampler);
        if(res != VK_SUCCESS){
            vizWarning << "vkCreateSampler(): VkResult " << (int32_t) res;
            return errors::sampler_cant_create();
        }
            
        m_info  = sam.info;
        return {};
    }
    
    void                ViSampler::_kill()
    {
        if(m_sampler){
            vkDestroySampler(m_device.device(), m_sampler, nullptr);
            m_sampler   = nullptr;
        }
    }
    
    void                ViSampler::_wipe()
    {
        m_sampler   = nullptr;
        m_info      = {};
    }

    void                ViSampler::kill()
    {
        if(valid()){
            _kill();
        }
        _wipe();
    }
}
