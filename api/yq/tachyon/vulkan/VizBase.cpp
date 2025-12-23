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

    VkInstance    VizBase::instance() 
    { 
        return VulqanManager::instance(); 
    }

    ///////////////////////////////////////////////////////////////////////////

    VizBase::VizBase(const Param& p) : m_device(p.device)
    {
        if(!m_device || !m_device->valid())
            return ;
            
        set_clear_color(p.clear_color);
        if(!_init_queues(p))
            return;
        if(!_init_depth(p))
            return;
        m_goodBase  = true;
    }
    
    VizBase::~VizBase()
    {
    }
    
    bool VizBase::Queue::init(ViDevice& dev, ViQueueType type, queue_spec qs, const ViQueueID& _id, uint32_t num)
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

    bool    VizBase::_init_depth(const Param& p)
    {
        if(std::get_if<std::monostate>(&p.depth_buffer))
            return true;

        if(std::get_if<enable_k>(&p.depth_buffer)){
            auto x = find_depth_format();
            if(!x)
                return false;
                
            m_depthBuffer.format    = *x;
        }
        
        if(auto* x = std::get_if<DataFormat>(&p.depth_buffer)){
            if(*x == DataFormat::UNDEFINED)
                return true;
            
            m_depthBuffer.format    = (VkFormat) x -> value();
        }
        
        m_depthBuffer.enable    = true;
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
            
        if(!m_graphicsQueue.init(*m_device, ViQueueType::Graphic, p.graphics, p.graphics_queue, p.graphics_number))
            return false;
        if(!m_presentQueue.init(*m_device, ViQueueType::Present, p.present, p.present_queue.valid() ? p.present_queue : m_graphicsQueue.id, p.present_number))
            return false;
        if(!m_computeQueue.init(*m_device, ViQueueType::Compute, p.compute, p.compute_queue, p.compute_number))
            return false;
        if(!m_transferQueue.init(*m_device, ViQueueType::Transfer, p.transfer, p.transfer_queue, p.transfer_number))
            return false;
        if(!m_opticalFlowQueue.init(*m_device, ViQueueType::OpticalFlow, p.optical_flow, p.optical_flow_queue, p.optical_flow_number))
            return false;
        if(!m_videoDecQueue.init(*m_device, ViQueueType::VideoDecode, p.video_decode, p.video_decode_queue, p.video_decode_number))
            return false;
        if(!m_videoEncQueue.init(*m_device, ViQueueType::VideoDecode, p.video_decode, p.video_encode_queue, p.video_encode_number))
            return false;
        return true;
    }


    RGBA4F VizBase::clear_color() const
    {
        VkClearValue    cv = m_clearValue;
        return vqExtractRGBA4F(cv);
    }

    VkQueue  VizBase::compute_queue() const
    {
        if(m_computeQueue.enable && m_device)
            return m_device -> queue(m_computeQueue.id);
        return nullptr;
    }
    
    std::error_code VizBase::compute_queue_task(queue_tasker_fn&&fn, const VizTaskerOptions& opts)
    {
        if(!fn)
            return errors::tasker_bad_function();
        if(!m_computeQueue.enable || !m_device || !m_device->valid())
            return errors::visualizer_uninitialized();
        return m_device->queue_task(m_computeQueue.id, opts.timeout, std::move(fn));
    }

    bool    VizBase::compute_queue_valid() const
    {
        return m_computeQueue.enable && m_device && m_device->is_queue_valid(m_computeQueue.id);
    }
    
    VkDevice            VizBase::device() const
    {
        return logical();
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
        if(!m_goodBase)
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


    VkQueue     VizBase::graphics_queue() const
    {
        if(m_graphicsQueue.enable && m_device)
            return m_device->queue(m_graphicsQueue.id);
        return nullptr;
    }
    
    bool        VizBase::graphics_queue_valid() const
    {
        return m_graphicsQueue.enable && m_device && m_device->is_queue_valid(m_graphicsQueue.id);
    }

    std::error_code VizBase::graphics_queue_task(queue_tasker_fn&&fn, const VizTaskerOptions& opts)
    {
        if(!fn)
            return errors::tasker_bad_function();
        if(!m_graphicsQueue.enable || !m_device || !m_device->valid())
            return errors::visualizer_uninitialized();
        return m_device->queue_task(m_graphicsQueue.id, opts.timeout, std::move(fn));
    }
    
    VkDevice    VizBase::logical() const
    {
        if(m_device)
            return m_device->device();
        return nullptr;
    }


    VkQueue      VizBase::optical_flow_queue() const
    {
        if(m_opticalFlowQueue.enable && m_device)
            return m_device -> queue(m_opticalFlowQueue.id);
        return nullptr;
    }

    std::error_code VizBase::optical_flow_queue_task(queue_tasker_fn&&fn, const VizTaskerOptions& opts)
    {
        if(!fn)
            return errors::tasker_bad_function();
        if(!m_opticalFlowQueue.enable || !m_device || !m_device->valid())
            return errors::visualizer_uninitialized();
        return m_device->queue_task(m_opticalFlowQueue.id, opts.timeout, std::move(fn));
    }

    bool        VizBase::optical_flow_queue_valid() const
    {
        return m_opticalFlowQueue.enable && m_device && m_device->is_queue_valid( m_opticalFlowQueue.id );
    }


    VkPhysicalDevice      VizBase::physical() const 
    { 
        if(m_device)
            return m_device->physical();
        return nullptr;
    }


    VkQueue      VizBase::present_queue() const
    {
        if(m_presentQueue.enable && m_device)
            return m_device -> queue(m_presentQueue.id);
        return nullptr;
    }

    std::error_code VizBase::present_queue_task(queue_tasker_fn&&fn, const VizTaskerOptions& opts)
    {
        if(!fn)
            return errors::tasker_bad_function();
        if(!m_presentQueue.enable || !m_device || !m_device->valid())
            return errors::visualizer_uninitialized();
        return m_device->queue_task(m_presentQueue.id, opts.timeout, std::move(fn));
    }

    bool        VizBase::present_queue_valid() const
    {
        return m_presentQueue.enable && m_device && m_device->is_queue_valid( m_presentQueue.id );
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

    void        VizBase::set_clear_color(const RGBA4F&i)
    {   
        m_clearValue    = vqClearValue(i);
    }


    VkQueue     VizBase::transfer_queue() const
    {
        if(m_transferQueue.enable && m_device)
            return m_device->queue(m_transferQueue.id);
        return nullptr;
    }
    
    std::error_code VizBase::transfer_queue_task(queue_tasker_fn&&fn, const VizTaskerOptions& opts)
    {
        if(!fn)
            return errors::tasker_bad_function();
        if(!m_transferQueue.enable || !m_device || !m_device->valid())
            return errors::visualizer_uninitialized();
        return m_device->queue_task(m_transferQueue.id, opts.timeout, std::move(fn));
    }

    bool    VizBase::transfer_queue_valid() const
    {
        return m_transferQueue.enable && m_device && m_device->is_queue_valid(m_transferQueue.id);
    }


    VkQueue   VizBase::video_decode_queue() const
    {
        if(m_videoDecQueue.enable && m_device)
            return m_device -> queue(m_videoDecQueue.id);
        return nullptr;
    }
    
    std::error_code VizBase::video_decode_queue_task(queue_tasker_fn&&fn, const VizTaskerOptions& opts)
    {
        if(!fn)
            return errors::tasker_bad_function();
        if(!m_videoDecQueue.enable || !m_device || !m_device->valid())
            return errors::visualizer_uninitialized();
        return m_device->queue_task(m_videoDecQueue.id, opts.timeout, std::move(fn));
    }

    bool        VizBase::video_decode_queue_valid() const
    {
        return m_videoDecQueue.enable && m_device && m_device->is_queue_valid(m_videoDecQueue.id);
    }

    VkQueue   VizBase::video_encode_queue() const
    {
        if(m_videoEncQueue.enable && m_device)
            return m_device->queue(m_videoEncQueue.id);
        return nullptr;
    }
    
    std::error_code VizBase::video_encode_queue_task(queue_tasker_fn&&fn, const VizTaskerOptions& opts)
    {
        if(!fn)
            return errors::tasker_bad_function();
        if(!m_videoEncQueue.enable || !m_device || !m_device->valid())
            return errors::visualizer_uninitialized();
        return m_device->queue_task(m_videoEncQueue.id, opts.timeout, std::move(fn));
    }

    bool        VizBase::video_encode_queue_valid() const
    {
        return m_videoEncQueue.enable && m_device && m_device->is_queue_valid(m_videoEncQueue.id);
    }

    std::error_code                 VizBase::wait_idle()
    {
        if(m_device)
            return m_device->wait_idle();
        return errors::visualizer_uninitialized();
    }
}
