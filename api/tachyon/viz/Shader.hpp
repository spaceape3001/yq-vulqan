////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/core/Memory.hpp>
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
        static std::string_view     name(const ShaderSpec&);
        
        virtual size_t      data_size() const override;
        
        Shader(ShaderType, Memory&&);

        const Memory      payload;
        const ShaderType  type;
    
    private:
        virtual ~Shader();
    };
}
