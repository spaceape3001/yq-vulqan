////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ShaderAsset.hpp"

#include <yq-vulqan/logging.hpp>
#include <yq-vulqan/asset/AssetFactory.hpp>
#include <yq-vulqan/asset/AssetInfoWriter.hpp>
#include <yq-toolbox/basic/DelayInit.hpp>
#include <yq-toolbox/text/format.hpp>

namespace yq::tachyon {
    TypedAssetFactory<ShaderAsset>&  ShaderAsset::cache()
    {
        static TypedAssetFactory<ShaderAsset>   s_ret;
        return s_ret;
    }

    Ref<const ShaderAsset>    ShaderAsset::decode(const ShaderSpec&ss)
    {
        if(Ref<const ShaderAsset> const * ptr = std::get_if<Ref<const ShaderAsset>>(&ss)){
            return *ptr;
        } else if(const std::string* ptr = std::get_if<std::string>(&ss)){
            return load(*ptr); 
        } else 
            return nullptr;
    }

    Ref<const ShaderAsset>    ShaderAsset::load(std::string_view pp)
    {
        return cache().load(pp);
    }

    std::string_view     ShaderAsset::name(const ShaderSpec&ss)
    {
        if(Ref<const ShaderAsset> const * ptr = std::get_if<Ref<const ShaderAsset>>(&ss)){
            if(!*ptr)
                return "(null)";
            auto& fp = (*ptr) -> filepath();
            if(fp.empty())
                return to_string_view((*ptr) -> id());
            return fp.c_str();
        } else if(const std::string* ptr = std::get_if<std::string>(&ss)){
            return *ptr; 
        } else 
            return "(nameless)";
    }

    ////////////////////////////////////////////////////////////////////////////////

    ShaderAsset::ShaderAsset(ShaderType st, Memory&& mem) : Asset(), payload(std::move(mem)), type(st)
    {
    }

    ShaderAsset::~ShaderAsset()
    {
    }

    size_t      ShaderAsset::data_size() const 
    {
        return payload.bytes();
    }

    ////////////////////////////////////////////////////////////////////////////////

    void    reg_shader_asset()
    {
        auto ti = writer<ShaderAsset>();
        ti.description("ShaderAsset Asset");
        ti.property("Type", &ShaderAsset::type);
    }

    YQ_INVOKE(reg_shader_asset();)
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::ShaderAsset)
