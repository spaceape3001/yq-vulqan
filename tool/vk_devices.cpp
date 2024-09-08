////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq-vulqan/v/VqUtils.hpp>
#include <yq-vulqan/app/Application.hpp>
#include <iostream>

using namespace yq;
using namespace yq::tachyon;

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

