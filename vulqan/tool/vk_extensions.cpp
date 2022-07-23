////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <engine/vulqan/VqUtils.hpp>
#include <iostream>

int main(int argc, char* argv[])
{
    auto data = yq::engine::vqEnumerateInstanceExtensionProperties();
    std::cout << data.size() << " vulkan extension(s)\n";
    for(const auto& lay : data)
        std::cout << '\t' << lay.extensionName << '\n';
    return 0;
}

