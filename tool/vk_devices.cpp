////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <engine/vulqan/VqUtils.hpp>
#include <engine/Application.hpp>
#include <iostream>

using namespace yq;
using namespace yq::engine;

int main(int argc, char* argv[])
{
    Application vi(argc, argv);
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

