////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Memory.hpp>
#include <yq/asset/Asset.hpp>
#include <yq/tachyon/enum/ShaderType.hpp>
#include <yq/tachyon/typedef/shader.hpp>

namespace yq::tachyon {

        //! Shader is a Vulkan compatible shader (compiled)
    class Shader : public Asset {
        YQ_OBJECT_DECLARE(Shader, Asset)
    public:
    
        //! Shader cache
        static TypedAssetFactory<Shader>&  cache();
        
        //! Loads the specified shader
        static Ref<const Shader>    load(std::string_view);
        
        //! Loads the specified shader
        static Ref<const Shader>    load(std::string_view, const AssetLoadOptions&);

        //! Decodes the specified shader
        static Ref<const Shader>    decode(const ShaderSpec&);
        
        //! Decodes the specified shader
        static Ref<const Shader>    decode(const ShaderSpec&, const AssetLoadOptions&);
        
        //! Gets the name to the specified shader
        static std::string_view     name(const ShaderSpec&);
        
        //! Size of the compiled shader 
        virtual size_t      data_size() const override;
        
        //! Shader constructor
        Shader(ShaderType, Memory&&);

        //! Shader bytecode
        const Memory      payload;
        
        //! Shader type
        const ShaderType  type;
    
    private:
        AssetFactory&       factory() const override;
        
        //! Private destructor as these are considered load-once and keep until application exit
        virtual ~Shader();
    };
}
