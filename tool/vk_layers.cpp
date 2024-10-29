////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/tachyon/v/VqUtils.hpp>
#include <iostream>

int main(int argc, char* argv[])
{
    auto data = yq::tachyon::vqEnumerateInstanceLayerProperties();
    std::cout << data.size() << " vulkan layer(s)\n";
    for(const auto& lay : data)
        std::cout << '\t' << lay.layerName << '\n';
    return 0;
}

