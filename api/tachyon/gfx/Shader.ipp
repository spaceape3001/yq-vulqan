////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/TachyonLog.hpp>
#include <tachyon/gfx/Shader.hpp>
#include <tachyon/core/AssetFactory.hpp>
#include <tachyon/core/AssetInfoWriter.hpp>
#include <basic/DelayInit.hpp>

namespace yq::tachyon {
    TypedAssetFactory<Shader>&  Shader::cache()
    {
        static TypedAssetFactory<Shader>   s_ret;
        return s_ret;
    }

    Ref<const Shader>    Shader::decode(const ShaderSpec&ss)
    {
        if(Ref<const Shader> const * ptr = std::get_if<Ref<const Shader>>(&ss)){
            return *ptr;
        } else if(const std::string* ptr = std::get_if<std::string>(&ss)){
            return load(*ptr); 
        } else 
            return nullptr;
    }

    Ref<const Shader>    Shader::load(std::string_view pp)
    {
        return cache().load(pp);
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

    namespace {
        void    reg_shader()
        {
            auto ti = writer<Shader>();
            ti.description("Shader Asset");
            ti.property("Type", &Shader::type);
        }

        YQ_INVOKE(reg_shader();)
    }

}

YQ_OBJECT_IMPLEMENT(yq::tachyon::Shader)
