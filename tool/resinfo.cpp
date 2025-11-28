////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/core/Logging.hpp>
#include <yq/process/PluginLoader.hpp>
#include <yq/tachyon/application.hpp>
#include <yq/tachyon/asset/AssetPak.hpp>
#include <yq/tachyon/asset/Mesh.hpp>
#include <yq/tachyon/asset/Material.hpp>
#include <yq/tachyon/asset/Raster.hpp>
#include <yq/tachyon/asset/Sampler.hpp>
#include <yq/tachyon/asset/Shader.hpp>
#include <yq/tachyon/asset/Texture.hpp>
#include <iostream>

using namespace yq;
using namespace yq::tachyon;

void    print_resource(const Resource& r, std::string_view pad={})
{
    std::cout << pad << r.metaInfo().stem() << " [" << r.url() << "][" << r.id() << "]: ";
}

void    print_material(const Material& )
{
}

void    print_mesh(const Mesh& msh)
{
    std::cout << "verts " << msh.vertex(COUNT) << ", indices " << msh.index.size();
}

void    print_raster(const Raster&ras)
{
    std::cout << ras.info.format.key() << ", ";
    std::cout << ras.info.size.x;
    if(ras.info.size.y){
        std::cout << " x " << ras.info.size.y;
        if(ras.info.size.z){
            std::cout << " x " << ras.info.size.z;
            if(ras.info.size.w){
                std::cout << " x " << ras.info.size.w;
            }
        }
    }
}

void    print_sampler(const Sampler&)
{
}

void    print_shader(const Shader&sh)
{
    std::cout << sh.type.key() << ", bytes=" << sh.data_size();
}

void    print_texture(const Texture&)
{
}


void    print_assetpak( const AssetPak& ap)
{
    std::cout << "\n";
    bool    f = true;
    for(auto & res : ap.resources()){
        if(!res)
            continue;
        if(f){
            f       = false;
        } else {
            std::cout << '\n';
        }
            
        print_resource(*res, "    ");
        if(const Material* p = dynamic_cast<const Material*>(res.ptr()))
            print_material(*p);
        if(const Mesh* p = dynamic_cast<const Mesh*>(res.ptr()))
            print_mesh(*p);
        if(const Raster* p = dynamic_cast<const Raster*>(res.ptr()))
            print_raster(*p);
        if(const Sampler* p = dynamic_cast<const Sampler*>(res.ptr()))
            print_sampler(*p);
        if(const Shader* p = dynamic_cast<const Shader*>(res.ptr()))
            print_shader(*p);
        if(const Texture* p = dynamic_cast<const Texture*>(res.ptr()))
            print_texture(*p);
    }
}

int main(int argc, char* argv[])
{
    //log_to_std_error();
    
    AppCreateInfo   aci;
    aci.headless    = true;
    Application app(argc, argv, aci);
    Meta::init();
    app.vulqan_libraries(LOAD);
    Meta::init();
    Meta::freeze();
    
    for(int n=1;n<argc;++n){
        ResourceCPtr    res = Resource::resource_load(std::string_view(argv[n]));
        if(!res){
            std::cout << "Resource [" << argv[n] << "] could not be loaded\n";
            continue;
        }
        print_resource(*res);
        if(const AssetPak* p = dynamic_cast<const AssetPak*>(res.ptr()))
            print_assetpak(*p);
        if(const Material* p = dynamic_cast<const Material*>(res.ptr()))
            print_material(*p);
        if(const Mesh* p = dynamic_cast<const Mesh*>(res.ptr()))
            print_mesh(*p);
        if(const Raster* p = dynamic_cast<const Raster*>(res.ptr()))
            print_raster(*p);
        if(const Sampler* p = dynamic_cast<const Sampler*>(res.ptr()))
            print_sampler(*p);
        if(const Shader* p = dynamic_cast<const Shader*>(res.ptr()))
            print_shader(*p);
        if(const Texture* p = dynamic_cast<const Texture*>(res.ptr()))
            print_texture(*p);
        std::cout << '\n';
    }
    
    return 0;
}
