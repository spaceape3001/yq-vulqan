////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/ByteArray.hpp>
#include <tachyon/core/Asset.hpp>
#include <tachyon/enum/ShaderType.hpp>

namespace yq::tachyon {

        //! Shader is a Vulkan compatible shader (compiled)
    class Shader : public Asset {
        YQ_OBJECT_DECLARE(Shader, Asset)
    public:
    
        static TypedAssetFactory<Shader>&  cache();
        
        static Ref<const Shader>    load(std::string_view);
        static Ref<const Shader>    decode(const ShaderSpec&);
        
        virtual size_t      data_size() const override;
        
        Shader(const ByteArray&, ShaderType);
        Shader(ByteArray&&, ShaderType);

        ByteArray   payload;
        ShaderType  type;
    
    private:
        virtual ~Shader();
    };
}
