////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////


#include <yq/asset/AssetMetaWriter.hpp>
#include <yq/asset/AssetIO.hpp>
#include <yq/core/DelayInit.hpp>
#include <yq/text/format.hpp>
#include <tachyon/logging.hpp>
#include <tachyon/asset/Shader.hpp>

namespace yq::tachyon {
    Ref<const Shader>    Shader::decode(const ShaderSpec&ss)
    {
        return decode(ss, AssetLoadOptions());
    }

    Ref<const Shader>    Shader::decode(const ShaderSpec&ss, const AssetLoadOptions& options)
    {
        if(Ref<const Shader> const * ptr = std::get_if<Ref<const Shader>>(&ss)){
            return *ptr;
        } else if(const std::string* ptr = std::get_if<std::string>(&ss)){
            return IO::load(*ptr, options); 
        } else 
            return nullptr;
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

    ////////////////////////////////////////////////////////////////////////////////

    void    Shader::init_meta()
    {
        auto ti = writer<Shader>();
        ti.description("Shader Asset");
        ti.property("Type", &Shader::type);
    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::Shader)
