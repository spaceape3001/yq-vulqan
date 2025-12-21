////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/vulkan/VqUtils.hpp>
#include <iostream>

int main(int argc, char* argv[])
{
    auto data = yq::tachyon::vqEnumerateInstanceExtensionProperties();
    std::cout << data.size() << " vulkan instance extension(s)\n";
    for(const auto& lay : data)
        std::cout << '\t' << lay.extensionName << '\n';
        
    //std::cout << '\n';
    //auto data2 = yq::tachyon::vqEnumerateDeviceExtensionProperties();
    //std::cout << data2.size() << " vulkan device extension(s)\n";
    //for(const auto& dev : data2)
        //std::cout << '\t' << dev.extensionName << '\n';
    
    
    return 0;
}

