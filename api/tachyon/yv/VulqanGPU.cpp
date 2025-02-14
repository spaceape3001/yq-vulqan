////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "VulqanGPU.hpp"
#include <yt/app/Application.hpp>
#include <yt/app/AppCreateInfo.hpp>
#include <yt/os/GraphicsCardInfoWriter.hpp>
#include <yv/ViDevice.hpp>
#include <yv/ViLogging.hpp>
#include <ya/requests/graphics_card/GetDeviceRequest.hpp>
#include "VqUtils.hpp"

namespace yq::tachyon {
    VulqanGPU::VulqanGPU(VkPhysicalDevice physDev) : m_physical(physDev)
    {
        m_name  = vqName(m_physical);
        
        const AppCreateInfo& aci    = Application::app()->app_info();
        
        vizInfo << "VulqanGPU(" << m_name << "): id=" << id().id;

        //  approximate... might have some error
        vkGetPhysicalDeviceMemoryProperties(m_physical, &m_memoryInfo);
        m_heap  = 0;
        for(size_t i=0;i<m_memoryInfo.memoryHeapCount;++i){
            if(m_memoryInfo.memoryHeaps[i].flags & VK_MEMORY_HEAP_DEVICE_LOCAL_BIT)
                m_heap += m_memoryInfo.memoryHeaps[i].size;
        }

        vizDebug << "VulqanGPU(" << m_name << "): heap=" << m_heap;

        VqPhysicalDeviceProperties2         prop2;
        VqPhysicalDeviceMultiviewProperties multiProp;
        
        vkGetPhysicalDeviceFeatures(m_physical, &m_deviceFeatures);
        vkGetPhysicalDeviceMemoryProperties(m_physical, &m_memoryInfo);

        if(aci.view.multiview){
            m_multiview.enabled  = true;
            prop2.pNext     = &multiProp;
            vizDebug << "VulqanGPU(" << m_name << "): Multiview enabled";
        }

        vkGetPhysicalDeviceProperties2(m_physical, &prop2);
        m_deviceInfo    = prop2.properties;
        if(aci.view.multiview){
            m_multiview.maxViewCount        = multiProp.maxMultiviewViewCount;
            m_multiview.maxInstanceIndex    = multiProp.maxMultiviewInstanceIndex;
        }
    }
    
    VulqanGPU::~VulqanGPU()
    {
    }

    void    VulqanGPU::kill()
    {
    }

    void      VulqanGPU::on_get_device_request(const GetDeviceRequest&req)
    {
    }

    Execution VulqanGPU::setup(const Context&ctx) 
    {
        return GraphicsCard::setup(ctx);
    }

    void VulqanGPU::snap(GraphicsCardSnap&sn) const
    {
        GraphicsCard::snap(sn);
        sn.name = m_name;
        sn.heap = m_heap;
    }

    void VulqanGPU::init_info()
    {
        auto w = writer<VulqanGPU>();
        w.description("Vulkan GPU");
        w.slot(&VulqanGPU::on_get_device_request);
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::VulqanGPU)
