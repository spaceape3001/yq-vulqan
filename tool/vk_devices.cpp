////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yt/keywords.hpp>
#include <yt/application.hpp>
#include <tachyon/vulkan/VqUtils.hpp>
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
        for(const auto& xp : vqEnumerateDeviceExtensionProperties(dev)){
            std::cout << "\t\t" << xp.extensionName << '\n';
        }
    }
    return 0;
}

