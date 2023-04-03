////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/ByteArray.hpp>
#include <tachyon/Asset.hpp>
#include <tachyon/enum/ShaderType.hpp>

namespace yq {
    namespace tachyon {

            //! Shader is a Vulkan compatible shader (compiled)
        class Shader : public Asset {
            YQ_OBJECT_DECLARE(Shader, Asset)
        public:
        
            static TypedAssetFactory<Shader>&  cache();
            
            static Ref<const Shader>    load(std::string_view);
            static Ref<const Shader>    decode(const ShaderSpec&);

            
            const ByteArray&    payload() const { return m_payload; }
            ShaderType          shader_type() const { return m_type; }
            virtual size_t      data_size() const override;
            
            
            Shader(const ByteArray&, ShaderType);
            Shader(ByteArray&&, ShaderType);
        
        private:
            virtual ~Shader();

            ByteArray               m_payload;
            tachyon::ShaderType     m_type;
        };
   }
}
