////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/core/DelayInit.hpp>
#include <yq/io/KeyValue.hpp>
#include <yq/tachyon/asset/material/BasicMaterial.hpp>
#include <yq/resource/Resource.hxx>

namespace {
    using namespace yq;
    using namespace yq::tachyon;
    
    MaterialPtr load_basic_kvtree(const KVTree& tree, const ResourceLoadAPI&api)
    {
        std::string_view    color       = tree.value("color");
        std::string_view    roughness   = tree.value("roughness");
        std::string_view    metallic    = tree.value("metallic");
        std::string_view    name        = tree.value("name");
        
        
        
        //BasicMaterial*      bm  = new BasicMaterial;
        //bm -> set_name(name);
        
        // TODO
        
        
        return {};
    }
    
    void    reg_mat_loader()
    {
        
        Material::IO::add_loader({ .extensions = { ".mat" } }, load_basic_kvtree);
    }
    
    YQ_INVOKE(reg_mat_loader();)
}
