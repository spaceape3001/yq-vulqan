////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <iostream>

#include <yq/container/ByteArray.hpp>
#include <yq/net/Url.hpp>
#include <yq/meta/Meta.hpp>
#include <yq/resource/Resource.hpp>
#include <yq/tachyon/application.hpp>
#include <yq/tachyon/io/GLSLShader.hpp>

using namespace yq;
using namespace yq::tachyon;

int main(int argc, char* argv[])
{
    if(argc < 2){
        std::cout << R"VOGON(
Usage:
    shexpand shader1 ... N
    
This will expand each shader and direct it to standard output.
)VOGON";

        return 0;
    }
    
    AppCreateInfo   aci;
    
    aci.vulkan.headless = true;
    aci.log_cerr        = LogPriority::Info;
    aci.log_cout        = {};
    Application app(argc, argv, aci);
    Meta::freeze();

    for(int n=1;n<argc;++n){
        Url url = Resource::resolve(argv[n]);
        auto [b,ec] = glsl::expand(url.path);
        if(ec != std::error_code()){
            std::cerr << "[" << argv[n] << "]: " << ec.message() << "\n";
            continue;
        }
        
        
        if(argc>2){
            std::cout << "\n===============================\n";
            std::cout << " >> " << argv[n] << "<<\n";
            std::cout << "\n===============================\n";
        }

        std::cout << std::string_view(b.data(), b.size());
    }
    
    return 0;
}
