////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <boost/ut.hpp>
#include <yq/file/FileResolver.hpp>
#include <yq/core/BasicApp.hpp>
#include <yq/core/Logging.hpp>
#include <yq/tachyon/application.hpp>
#include <yq/tachyon/shader.hpp>

namespace ut = boost::ut;
using namespace ut;
using namespace yq;
using namespace yq::tachyon;

ut::suite tests = []{
    "resolving"_test = []{
        //const auto&     resolver    = Resource::resolver();
        
        //std::filesystem::path   pp  = resolver.partial("hello.frag");
        //expect(false == pp.empty());
        
        Url   rp  = Resource::resolve("sdk/hello/hello.frag");
        expect(false == rp.path.empty());
    };
    
    "loading"_test = []{
        const Shader*   s   = Shader::IO::load("sdk/hello/hello.frag");
        expect(nullptr != s);
        if(s){
            expect(s->type == ShaderType::FRAG);
        }

    };
};

int main()
{
    log_to_std_output();
    Meta::init();
    configure_standand_resource_path();
    Meta::init();

    #if 0
    const auto paths   = Resource::all_paths();
    yInfo() << "Resolver has " << paths.size() << " path(s)\n";
    size_t n=1;
    for(const auto& f : paths)
        yInfo() << (n++) << ") " << f.string() << "\n";
    #endif
    
    return ut::cfg<>.run();
};


