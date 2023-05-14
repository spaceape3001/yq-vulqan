////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <boost/ut.hpp>
#include <io/FileResolver.hpp>
#include <tachyon/viz/Shader.hpp>
#include <basic/Logging.hpp>

namespace ut = boost::ut;
using namespace ut;
using namespace yq;
using namespace yq::tachyon;

ut::suite tests = []{
    "resolving"_test = []{
        const auto&     resolver    = Asset::resolver();
        
        std::filesystem::path   pp  = resolver.partial("hello.frag");
        expect(false == pp.empty());
        
        std::filesystem::path   rp  = resolver.resolve("sdk/hello/hello.frag");
        expect(false == rp.empty());
    };
    
    "loading"_test = []{
        const Shader*   s   = Shader::load("sdk/hello/hello.frag");
        expect(nullptr != s);
        expect(s->type == ShaderType::FRAG);
    };
};

int main()
{
    log_to_std_output();

    Meta::init();

    #if 0
    const auto& resolver    = tachyon::Asset::resolver();
    const auto& paths   = resolver.paths();
    std::cout << "Resolver has " << paths.size() << " path(s)\n";
    size_t n=1;
    for(const auto& f : paths)
        std::cout << (n++) << ") " << f.string() << "\n";
    #endif
    
    return ut::cfg<>.run();
};


