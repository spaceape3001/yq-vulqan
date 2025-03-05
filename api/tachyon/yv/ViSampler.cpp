////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yv/ViSampler.hpp>

#include <yt/errors.hpp>
#include <yt/logging.hpp>
#include <yt/gfx/Sampler.hpp>
#include <yv/VqStructs.hpp>
#include <yv/ViDevice.hpp>

#include <yv/ViLogging.hpp>

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

    ViSampler::ViSampler()
    {
    }
    
    ViSampler::ViSampler(ViDevice& viz, const Sampler& sam)
    {
        if(viz.device()){
            std::error_code ec  = _init(viz, sam);
            if(ec != std::error_code()){
                vizWarning << "unable to create a sampler: " << ec.message();
                _wipe();
            }
        }
    }
    
    ViSampler::~ViSampler()
    {
        kill();
    }

    std::error_code     ViSampler::_init(ViDevice&viz, const Sampler&sam)
    {
        VkSamplerCreateInfo sci = vkInfo(viz, sam.info);
        
        m_device    = viz.device();

        VkResult res = vkCreateSampler(m_device, &sci, nullptr, &m_sampler);
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
            vkDestroySampler(m_device, m_sampler, nullptr);
            m_sampler   = nullptr;
        }
    }
    
    void                ViSampler::_wipe()
    {
        m_device    = nullptr;
        m_sampler   = nullptr;
        m_info      = {};
    }
    
    bool                ViSampler::consistent() const
    {
        return m_device ? static_cast<bool>(m_sampler) : !m_sampler;
    }
    
    std::error_code     ViSampler::init(ViDevice& viz, const Sampler& sam)
    {
        if(m_device){
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
        return m_device && m_sampler;
    }
}
