////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq/core/DelayInit.hpp>
#include <yq/keyv/KeyValue.hpp>
#include <yq/tachyon/asset/material/BasicMaterial.hpp>
#include <yq/text/parse.hpp>
#include <yq/resource/Resource.hxx>

namespace {
    using namespace yq;
    using namespace yq::tachyon;
    
    MaterialPtr load_basic_kvtree(const KVTree& tree, const ResourceLoadAPI&api)
    {
        BasicMaterial*      bm  = new BasicMaterial;
        bm -> set_name(tree.value("name"));

        if(auto x = to_rgba4f(tree.value("color")))
            bm -> color     = *x;
        if(auto x = to_float(tree.value("roughness")))
            bm -> roughness = *x;
        if(auto x = to_float(tree.value("metallic")))
            bm -> metallic  = *x;
        return bm;
    }
    
    void    reg_mat_loader()
    {
        
        Material::IO::add_loader({ .extensions = { ".mat" } }, load_basic_kvtree);
    }
    
    YQ_INVOKE(reg_mat_loader();)
}
