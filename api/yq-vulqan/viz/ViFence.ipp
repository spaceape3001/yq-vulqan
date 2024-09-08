////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ViFence.hpp"
#include <yq-vulqan/errors.hpp>
#include <yq-vulqan/v/VqStructs.hpp>
#include <yq-vulqan/viz/ViVisualizer.hpp>

namespace yq::tachyon {
    ViFence::ViFence()
    {
    }
    
    ViFence::~ViFence()
    {
    }


    std::error_code ViFence::init(ViVisualizer&viz)
    {
        if(!consistent())
            return errors::BAD_STATE_FENCE();
        if(valid())
            return errors::EXISTING_FENCE();
        
        VqFenceCreateInfo   fci;
        VkResult res = vkCreateFence(viz.device(), &fci, nullptr, &m_fence);
        if(res != VK_SUCCESS){
            m_fence = nullptr;
            return errors::CANT_CREATE_FENCE();
        }
        
        m_viz   = &viz;
        return {};
    }
    
    bool            ViFence::consistent() const
    {
        return m_viz ? (m_fence && m_viz->device()) : !m_fence;
    }

    void            ViFence::kill()
    {
        if(valid())
            vkDestroyFence(m_viz->device(), m_fence, nullptr);
        m_viz   = nullptr;
        m_fence = nullptr;
    }
    
    ViFenceStatus ViFence::status() const
    {
        if(!valid())
            return ViFenceStatus::Uninitialized;
            
        switch(vkGetFenceStatus(m_viz->device(), m_fence)){
        case VK_SUCCESS:
            return ViFenceStatus::Ready;
        case VK_NOT_READY:
            return ViFenceStatus::NotReady;
        case VK_ERROR_DEVICE_LOST:
            return ViFenceStatus::DeviceLost;
        default:
            return ViFenceStatus::GenericError;
        }
    }
    
    bool            ViFence::valid() const
    {
        return m_viz && m_fence && m_viz->device();
    }
}
