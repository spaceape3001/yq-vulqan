////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/asset/Shader.hpp>
#include <tachyon/asset/AssetFactory.hpp>
#include <tachyon/asset/AssetInfoWriter.hpp>
#include <basic/DelayInit.hpp>

namespace yq {
    namespace tachyon {
        TypedAssetFactory<Shader>&  Shader::cache()
        {
            static TypedAssetFactory<Shader>   s_ret;
            return s_ret;
        }

        const Shader*    Shader::load(std::string_view pp)
        {
            return cache().load(pp);
        }

        ////////////////////////////////////////////////////////////////////////////////

        Shader::Shader(const ByteArray&b, ShaderType st) : Asset(), m_payload(b), m_type(st)
        {
        }
        
        Shader::Shader(ByteArray&& b, ShaderType st) : Asset(), m_payload(std::move(b)), m_type(st)
        {
        }
    
        Shader::~Shader()
        {
        }

        size_t      Shader::data_size() const 
        {
            return m_payload.size();
        }

        ////////////////////////////////////////////////////////////////////////////////

        namespace {
            void    reg_shader()
            {
                auto ti = writer<Shader>();
                ti.description("Shader Asset");
            }

            YQ_INVOKE(reg_shader();)
        }

    }
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::Shader)
