////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "VizBase.hpp"
#include <yq/container/initlist_utils.hpp>
#include <yq/tachyon/errors.hpp>
#include <yq/tachyon/vulkan/ViDevice.hpp>
#include <yq/tachyon/vulkan/ViLogging.hpp>
#include <yq/tachyon/vulkan/ViManager.hpp>
#include <yq/tachyon/vulkan/ViPipeline.hpp>
#include <yq/tachyon/vulkan/ViProcessor.hpp>
#include <yq/tachyon/vulkan/VqStructs.hpp>
#include <yq/tachyon/vulkan/VqUtils.hpp>
#include <yq/tachyon/vulkan/VulqanManager.hpp>

namespace yq::tachyon {

    std::string_view    key_for(ViQueueType qt)
    {
        switch(qt){
        case ViQueueType::Auto:
            return "auto";
        case ViQueueType::Graphic:
            return "graphics";
        case ViQueueType::Present:
            return "present";
        case ViQueueType::Compute:
            return "compute";
        case ViQueueType::Transfer:
            return "transfer";
        case ViQueueType::OpticalFlow:
            return "optical_flow";
        case ViQueueType::VideoEncode:
            return "video_enc";
        case ViQueueType::VideoDecode:
            return "video_dec";
        default:
            return "unknown";
        }
    }

    ///////////////////////////////////////////////////////////////////////////

    VizBase::compute_t::compute_t() : processing_t(ViQueueType::Compute)
    {
    }
    
    ///////////////////////////////////////////////////////////////////////////

    VizBase::graphics_t::graphics_t() : processing_t(ViQueueType::Graphic)
    {
    }

    ///////////////////////////////////////////////////////////////////////////

    VizBase::optical_flow_t::optical_flow_t() : processing_t(ViQueueType::OpticalFlow)
    {
    }

    ///////////////////////////////////////////////////////////////////////////

    VizBase::present_t::present_t() : queue_t(ViQueueType::Present)
    {
    }

    ///////////////////////////////////////////////////////////////////////////
    
    VizBase::processing_t::processing_t(ViQueueType qt) : queue_t(qt)
    {
        //factory = []() -> ViProcessingUPtr
    }
    
    VizBase::processing_t::~processing_t()
    {
    }

    bool        VizBase::processing_t::pExpand(uint32_t n)
    {
        if(!factory)
            return false;
        
        procs.reserve(n);
        while(procs.size() < n){
            auto pp = factory();
            if(!pp)
                return false;
            set_id(*pp, (uint32_t) procs.size());
            procs.push_back(std::move(pp));
        }
        return true;
    }

    void        VizBase::processing_t::pInit(VizBase* vb)
    {
        factory = [vb,this]() -> ViProcessorUPtr {
            return std::make_unique<ViProcessor>(*vb, type);
        };
    }

    ViProcessor*    VizBase::processing_t::proc(uint32_t i) const
    {
        if(i >= procs.size())
            return nullptr;
        return procs[i].get();
    }

    void VizBase::processing_t::reset()
    {
        factory = {};
        procs.clear();
    }

    ///////////////////////////////////////////////////////////////////////////

    VizBase::queue_t::queue_t(ViQueueType qt) : type(qt)
    {
    }

    bool VizBase::queue_t::qInit(ViDevice& dev, queue_spec qs, const ViQueueID& _id, uint32_t num)
    {
        if(std::get_if<std::monostate>(&qs))
            return true;
        
        if(_id.valid()){
            id  = _id;
        } else {
            id  = { dev.queue_family(type), num };
        }
        
        if(dev.is_queue_valid(id)){
            enable  = true;
            return true;
        }
        
        if(std::get_if<required_k>(&qs)){
            vizError << "VizBase: No " << key_for(type) << " queue detected.";
            return false;
        }
        
        if(std::get_if<optional_k>(&qs)){
            vizNotice << "VizBase: No " << key_for(type) << " queue detected.";
            return true;
        }

        if(std::get_if<device_k>(&qs))
            return true;
            
        return false;   //< Shouldn't ever get here...
    }
    
    
    ///////////////////////////////////////////////////////////////////////////

    VizBase::transfer_t::transfer_t() : queue_t(ViQueueType::Transfer)
    {
    }

    ///////////////////////////////////////////////////////////////////////////

    VizBase::video_t::video_t(ViQueueType qt) : processing_t(qt)
    {
    }
    
    ///////////////////////////////////////////////////////////////////////////

    VizBase::video_decode_t::video_decode_t() : video_t(ViQueueType::VideoDecode)
    {
    }

    ///////////////////////////////////////////////////////////////////////////

    VizBase::video_encode_t::video_encode_t() : video_t(ViQueueType::VideoEncode)
    {
    }

    ///////////////////////////////////////////////////////////////////////////

    VkInstance    VizBase::instance() 
    { 
        return VulqanManager::instance(); 
    }

    void VizBase::set_id(ViProcessor&vp, uint32_t i)
    {
        vp.m_id = i;
    }


    ///////////////////////////////////////////////////////////////////////////

    VizBase::VizBase(ViDevice& dev, const Param& p) : m_device(&dev), 
        m_descriptorPool(dev, std::clamp(p.descriptors, MIN_DESCRIPTOR_COUNT, MAX_DESCRIPTOR_COUNT))
    {
        if(!dev.valid())
            return ;
            
        color_clear(SET, p.color_clear);
        if(!_init_queues(p))
            return;
        if(!_init_depth(p))
            return;
            
        m_compute.pInit(this);
        m_graphics.pInit(this);
        m_opticalFlow.pInit(this);
        m_videoDec.pInit(this);
        m_videoEnc.pInit(this);
        m_pipelines     = std::make_unique<ViPipelineManager>(*this, ViPipelineOptions());

vizInfo << "VizBase(" << id() << ", graphic " << p.graphics_qidx << ") to get queue " << hex(graphics_queue());
            
        m_good  = true;
    }
    
    VizBase::~VizBase()
    {
        m_compute.reset();
        m_graphics.reset();
        m_opticalFlow.reset();
        m_videoDec.reset();
        m_videoEnc.reset();
        m_pipelines = {};
    }
    

    bool    VizBase::_init_depth(const Param& p)
    {
        if(std::get_if<std::monostate>(&p.depth_buffer))
            return true;

        if(std::get_if<enable_k>(&p.depth_buffer)){
            auto x = find_depth_format();
            if(!x)
                return false;
                
            m_depth.format    = *x;
        }
        
        if(auto* x = std::get_if<DataFormat>(&p.depth_buffer)){
            if(*x == DataFormat::UNDEFINED)
                return true;
            
            m_depth.format    = (VkFormat) x -> value();
        }
        
        m_depth.enable    = true;
        return true;
    }

    bool    VizBase::_init_queues(const Param&p)
    {

            //  If you're debugging the present queue... means it's fouled up.  
            //  In order to break the surface dependency for the device, we
            //  assumed that it's generally available on the graphic queue.
            //  However, if that's not the case, then the vulkan create info
            //  needs to have the relevant queue enabled *AND* it needs to be
            //  set on the create data structure.
            
        if(!m_graphics.qInit(*m_device, p.graphics, p.graphics_queue, p.graphics_qidx))
            return false;
        if(!m_present.qInit(*m_device, p.present, p.present_queue.valid() ? p.present_queue : m_graphics.id, p.present_qidx))
            return false;
        if(!m_compute.qInit(*m_device, p.compute, p.compute_queue, p.compute_qidx))
            return false;
        if(!m_transfer.qInit(*m_device, p.transfer, p.transfer_queue, p.transfer_qidx))
            return false;
        if(!m_opticalFlow.qInit(*m_device, p.optical_flow, p.optical_flow_queue, p.optical_flow_qidx))
            return false;
        if(!m_videoDec.qInit(*m_device, p.video_decode, p.video_decode_queue, p.video_decode_qidx))
            return false;
        if(!m_videoEnc.qInit(*m_device, p.video_decode, p.video_encode_queue, p.video_encode_qidx))
            return false;
        return true;
    }

    RGBA4F VizBase::color_clear() const
    {
        return vqExtractRGBA4F(m_color.clear);
    }

    void        VizBase::color_clear(set_k, const RGBA4F&i)
    {   
        m_color.clear   = vqClearValue(i);
    }

    void     VizBase::color_format(set_k, DataFormat v)
    {
        m_color.format  = (VkFormat) v.value();
    }
    
    void     VizBase::color_format(set_k, VkFormat v)
    {
        m_color.format  = v;
    }

    void     VizBase::color_space(set_k, VkColorSpaceKHR v)
    {
        m_color.space   = v;
    }

    ViProcessor*    VizBase::compute_processor(uint32_t n)
    {
        return m_compute.proc(n);
    }

    bool     VizBase::compute_processor_expand(uint32_t n)
    {
        return m_compute.pExpand(n);
    }

    void    VizBase::compute_processor_factory(set_k, processor_create_t&&fn)
    {
        if(!fn)
            return;
        m_compute.factory   = std::move(fn);
    }

    VkQueue  VizBase::compute_queue() const
    {
        if(m_compute.enable && m_device)
            return m_device -> queue(m_compute.id);
        return nullptr;
    }
    
    std::error_code VizBase::compute_queue_task(queue_tasker_fn&&fn, const VizTaskerOptions& opts)
    {
        if(!fn)
            return errors::tasker_bad_function();
        if(!m_compute.enable || !m_device || !m_device->valid())
            return errors::visualizer_uninitialized();
        return m_device->queue_task(m_compute.id, opts.timeout, std::move(fn));
    }

    bool    VizBase::compute_queue_valid() const
    {
        return m_compute.enable && m_device && m_device->is_queue_valid(m_compute.id);
    }

    Expect<VkFormat>    VizBase::find_depth_format() const
    {
        return find_supported_format(
            {VK_FORMAT_D32_SFLOAT, VK_FORMAT_D32_SFLOAT_S8_UINT, VK_FORMAT_D24_UNORM_S8_UINT}, 
            VK_IMAGE_TILING_OPTIMAL,
            VK_FORMAT_FEATURE_DEPTH_STENCIL_ATTACHMENT_BIT
        );
    }

    Expect<VkFormat>    VizBase::find_supported_format(std::initializer_list<VkFormat> candidates, VkImageTiling tiling, VkFormatFeatureFlags features) const
    {
        return find_supported_format(span(candidates), tiling, features);
    }
    
    Expect<VkFormat>    VizBase::find_supported_format(std::span<const VkFormat> candidates, VkImageTiling tiling, VkFormatFeatureFlags features) const
    {
        if(!m_good)
            return errors::visualizer_uninitialized();

        for(VkFormat format : candidates){
            VkFormatProperties props;
            vkGetPhysicalDeviceFormatProperties(physical(), format, &props);
            
            switch(tiling){
            case VK_IMAGE_TILING_LINEAR:
                if((props.linearTilingFeatures & features) == features)
                    return format;
                break;
            case VK_IMAGE_TILING_OPTIMAL:
                if((props.optimalTilingFeatures & features) == features)
                    return format;
                break;
            default:
                break;
            }            
        }
        
        return errors::format_unsupported();
    }

    ViProcessor*    VizBase::graphics_processor(uint32_t n)
    {
        return m_graphics.proc(n);
    }

    bool            VizBase::graphics_processor_expand(uint32_t n)
    {
        return m_graphics.pExpand(n);
    }

    void    VizBase::graphics_processor_factory(set_k, processor_create_t&&fn)
    {
        if(!fn)
            return;
        m_graphics.factory  = std::move(fn);
    }

    VkQueue     VizBase::graphics_queue() const
    {
        if(m_graphics.enable && m_device)
            return m_device->queue(m_graphics.id);
        return nullptr;
    }
    
    std::error_code VizBase::graphics_queue_task(queue_tasker_fn&&fn, const VizTaskerOptions& opts)
    {
        if(!fn)
            return errors::tasker_bad_function();
        if(!m_graphics.enable || !m_device || !m_device->valid())
            return errors::visualizer_uninitialized();
        return m_device->queue_task(m_graphics.id, opts.timeout, std::move(fn));
    }

    bool        VizBase::graphics_queue_valid() const
    {
        return m_graphics.enable && m_device && m_device->is_queue_valid(m_graphics.id);
    }

    
    ViProcessor*    VizBase::optical_flow_processor(uint32_t n)
    {
        return m_opticalFlow.proc(n);
    }

    void    VizBase::optical_flow_processor_factory(set_k, processor_create_t&& fn)
    {
        if(!fn)
            return;
        m_opticalFlow.factory = std::move(fn);
    }

    VkQueue      VizBase::optical_flow_queue() const
    {
        if(m_opticalFlow.enable && m_device)
            return m_device -> queue(m_opticalFlow.id);
        return nullptr;
    }

    std::error_code VizBase::optical_flow_queue_task(queue_tasker_fn&&fn, const VizTaskerOptions& opts)
    {
        if(!fn)
            return errors::tasker_bad_function();
        if(!m_opticalFlow.enable || !m_device || !m_device->valid())
            return errors::visualizer_uninitialized();
        return m_device->queue_task(m_opticalFlow.id, opts.timeout, std::move(fn));
    }

    bool        VizBase::optical_flow_queue_valid() const
    {
        return m_opticalFlow.enable && m_device && m_device->is_queue_valid( m_opticalFlow.id );
    }
    
    ViPipelineCPtr                  VizBase::pipeline(uint64_t i) const
    {
        if(!m_pipelines)
            return {};
        return m_pipelines -> get(i);
    }
    
    ViPipelineCPtr                  VizBase::pipeline_create(const Pipeline* pipe)
    {
        if(!m_pipelines)
            return {};
        if(!pipe)
            return {};
        return m_pipelines -> create(pipe);
    }
    
    void                            VizBase::pipeline_erase(uint64_t i)
    {
        if(m_pipelines)
            m_pipelines -> erase(i);
    }
    
    void                            VizBase::pipeline_erase(const Pipeline* p)
    {
        if(p){
            pipeline_erase(p->id());
        }
    }
    
    ViPipelineManager*              VizBase::pipeline_manager() const
    {
        return m_pipelines.get();
    }


    VkQueue      VizBase::present_queue() const
    {
        if(m_present.enable && m_device)
            return m_device -> queue(m_present.id);
        return nullptr;
    }

    std::error_code VizBase::present_queue_task(queue_tasker_fn&&fn, const VizTaskerOptions& opts)
    {
        if(!fn)
            return errors::tasker_bad_function();
        if(!m_present.enable || !m_device || !m_device->valid())
            return errors::visualizer_uninitialized();
        return m_device->queue_task(m_present.id, opts.timeout, std::move(fn));
    }

    bool        VizBase::present_queue_valid() const
    {
        return m_present.enable && m_device && m_device->is_queue_valid( m_present.id );
    }


    std::error_code     VizBase::queue_task(ViQueueType qt, queue_tasker_fn&&fn, const VizTaskerOptions& opts)
    {
        switch(qt){
        case ViQueueType::Auto:
            return graphics_queue_task(std::move(fn), opts);
        case ViQueueType::Graphic:
            return graphics_queue_task(std::move(fn), opts);
        case ViQueueType::Present:
            return present_queue_task(std::move(fn), opts);
        case ViQueueType::Compute:
            return compute_queue_task(std::move(fn), opts);
        case ViQueueType::VideoEncode:
            return video_encode_queue_task(std::move(fn), opts);
        case ViQueueType::VideoDecode:
            return video_decode_queue_task(std::move(fn), opts);
        case ViQueueType::Transfer:
            return transfer_queue_task(std::move(fn), opts);
        case ViQueueType::OpticalFlow:
            return optical_flow_queue_task(std::move(fn), opts);
        default:
            //  shrugs... how?
            return graphics_queue_task(std::move(fn), opts);
        }
    }

    VkQueue     VizBase::transfer_queue() const
    {
        if(m_transfer.enable && m_device)
            return m_device->queue(m_transfer.id);
        return nullptr;
    }
    
    std::error_code VizBase::transfer_queue_task(queue_tasker_fn&&fn, const VizTaskerOptions& opts)
    {
        if(!fn)
            return errors::tasker_bad_function();
        if(!m_transfer.enable || !m_device || !m_device->valid())
            return errors::visualizer_uninitialized();
        return m_device->queue_task(m_transfer.id, opts.timeout, std::move(fn));
    }

    bool    VizBase::transfer_queue_valid() const
    {
        return m_transfer.enable && m_device && m_device->is_queue_valid(m_transfer.id);
    }

    ViProcessor*    VizBase::video_decode_processor(uint32_t n)
    {
        return m_videoDec.proc(n);
    }

    void    VizBase::video_decode_processor_factory(set_k, processor_create_t&& fn)
    {
        if(!fn)
            return;
        m_videoDec.factory = std::move(fn);
    }

    VkQueue   VizBase::video_decode_queue() const
    {
        if(m_videoDec.enable && m_device)
            return m_device -> queue(m_videoDec.id);
        return nullptr;
    }
    
    std::error_code VizBase::video_decode_queue_task(queue_tasker_fn&&fn, const VizTaskerOptions& opts)
    {
        if(!fn)
            return errors::tasker_bad_function();
        if(!m_videoDec.enable || !m_device || !m_device->valid())
            return errors::visualizer_uninitialized();
        return m_device->queue_task(m_videoDec.id, opts.timeout, std::move(fn));
    }

    bool        VizBase::video_decode_queue_valid() const
    {
        return m_videoDec.enable && m_device && m_device->is_queue_valid(m_videoDec.id);
    }

    ViProcessor*    VizBase::video_encode_processor(uint32_t n)
    {
        return m_videoEnc.proc(n);
    }

    void    VizBase::video_encode_processor_factory(set_k, processor_create_t&& fn)
    {
        if(!fn)
            return;
        m_videoEnc.factory = std::move(fn);
    }

    VkQueue   VizBase::video_encode_queue() const
    {
        if(m_videoEnc.enable && m_device)
            return m_device->queue(m_videoEnc.id);
        return nullptr;
    }
    
    std::error_code VizBase::video_encode_queue_task(queue_tasker_fn&&fn, const VizTaskerOptions& opts)
    {
        if(!fn)
            return errors::tasker_bad_function();
        if(!m_videoEnc.enable || !m_device || !m_device->valid())
            return errors::visualizer_uninitialized();
        return m_device->queue_task(m_videoEnc.id, opts.timeout, std::move(fn));
    }

    bool        VizBase::video_encode_queue_valid() const
    {
        return m_videoEnc.enable && m_device && m_device->is_queue_valid(m_videoEnc.id);
    }

    VkDevice    VizBase::vk_device() const
    {
        if(m_device)
            return m_device->device();
        return nullptr;
    }


    VkPhysicalDevice      VizBase::vk_physical_device() const 
    { 
        if(m_device)
            return m_device->physical();
        return nullptr;
    }


    std::error_code                 VizBase::wait_idle()
    {
        if(m_device)
            return m_device->wait_idle();
        return errors::visualizer_uninitialized();
    }
}
