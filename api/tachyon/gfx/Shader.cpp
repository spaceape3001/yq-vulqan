////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////


#include <yq/asset/AssetFactory.hpp>
#include <yq/asset/AssetMetaWriter.hpp>
#include <yq/asset/AssetIO.hpp>
#include <yq/core/DelayInit.hpp>
#include <yq/text/format.hpp>
#include <tachyon/logging.hpp>
#include <tachyon/gfx/Shader.hpp>

namespace yq::tachyon {
    TypedAssetFactory<Shader>&  Shader::cache()
    {
        static TypedAssetFactory<Shader>   s_ret;
        return s_ret;
    }

    Ref<const Shader>    Shader::decode(const ShaderSpec&ss)
    {
        return decode(ss, AssetLoadOptions());
    }

    Ref<const Shader>    Shader::decode(const ShaderSpec&ss, const AssetLoadOptions& options)
    {
        if(Ref<const Shader> const * ptr = std::get_if<Ref<const Shader>>(&ss)){
            return *ptr;
        } else if(const std::string* ptr = std::get_if<std::string>(&ss)){
            return load(*ptr, options); 
        } else 
            return nullptr;
    }

    Ref<const Shader>    Shader::load(std::string_view pp)
    {
        return load(pp, AssetLoadOptions());
    }

    Ref<const Shader>    Shader::load(std::string_view pp, const AssetLoadOptions& options)
    {
        return cache().load(pp, options);
    }

    std::string       Shader::name(const ShaderSpec&ss)
    {
        if(Ref<const Shader> const * ptr = std::get_if<Ref<const Shader>>(&ss)){
            if(!*ptr)
                return "(null)";
            auto& url = (*ptr) -> url();
            if(url.empty())
                return to_string((*ptr) -> id());
            return to_string(url);
        } else if(const std::string* ptr = std::get_if<std::string>(&ss)){
            return *ptr; 
        } else 
            return "(nameless)";
    }

    ////////////////////////////////////////////////////////////////////////////////

    Shader::Shader(ShaderType st, Memory&& mem) : Asset(), payload(std::move(mem)), type(st)
    {
    }

    Shader::~Shader()
    {
    }

    size_t      Shader::data_size() const 
    {
        return payload.bytes();
    }

    AssetFactory&       Shader::factory() const 
    {
        return cache();
    }

    ////////////////////////////////////////////////////////////////////////////////

    void    Shader::init_meta()
    {
        auto ti = writer<Shader>();
        ti.description("Shader Asset");
        ti.property("Type", &Shader::type);
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::Shader)
