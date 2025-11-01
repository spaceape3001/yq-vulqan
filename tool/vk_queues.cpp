////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/application.hpp>
#include <yq/tachyon/vulkan/VqUtils.hpp>
#include <iostream>

using namespace yq;
using namespace yq::tachyon;

int main(int argc, char* argv[])
{
    AppCreateInfo aci;
    aci.headless        = true;
    aci.platform        = NONE;
    aci.thread.viewer   = DISABLED;
    Application vi(argc, argv, aci);
    vi.start();
    auto data = vqEnumeratePhysicalDevices();
    std::cout << data.size() << " physical device(s)\n";
    for(const auto& dev : data){
        VkPhysicalDeviceProperties  props;
        vkGetPhysicalDeviceProperties(dev, &props);
        std::cout << '\t' << props.deviceName  << '\n';
        uint32_t    i   = 0;
        for(const auto& qp : vqGetPhysicalDeviceQueueFamilyProperties(dev)){
            std::cout << "\t\t" << i << ": (count=" << qp.queueCount 
                << ", minImage="<< qp.minImageTransferGranularity.width << "*" << qp.minImageTransferGranularity.height 
                << "*" << qp.minImageTransferGranularity.depth << ", timestamp bits=" << qp.timestampValidBits << "):";
            if(qp.queueFlags&VK_QUEUE_GRAPHICS_BIT)
                std::cout << " GRAPHICS";
            if(qp.queueFlags&VK_QUEUE_COMPUTE_BIT)
                std::cout << " COMPUTE";
            if(qp.queueFlags&VK_QUEUE_TRANSFER_BIT)
                std::cout << " TRANSFER";
            if(qp.queueFlags&VK_QUEUE_SPARSE_BINDING_BIT)
                std::cout << " SPARSE";
            if(qp.queueFlags&VK_QUEUE_PROTECTED_BIT)
                std::cout << " PROTECTED";
            if(qp.queueFlags&VK_QUEUE_VIDEO_DECODE_BIT_KHR)
                std::cout << " DECODE";
            if(qp.queueFlags&VK_QUEUE_VIDEO_ENCODE_BIT_KHR)
                std::cout << " ENCODE";
            if(qp.queueFlags&VK_QUEUE_OPTICAL_FLOW_BIT_NV)
                std::cout << " OPTICAL";
            std::cout << "\n";
            ++i;
        }
    }
    return 0;
}

