////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-vulqan/asset/Asset.hpp>
#include <yq-vulqan/memory/Memory.hpp>
#include <yq-vulqan/shader/ShaderType.hpp>
#include <yq-vulqan/typedef/shader.hpp>

namespace yq::tachyon {
    template <typename> class TypedAssetFactory;

        //! Shader is a Vulkan compatible shader (compiled)
    class ShaderAsset : public Asset {
        YQ_OBJECT_DECLARE(ShaderAsset, Asset)
    public:
    
        //! Shader cache
        static TypedAssetFactory<ShaderAsset>&  cache();
        
        //! Loads the specified shader
        static Ref<const ShaderAsset>    load(std::string_view);
        
        //! Decodes the specified shader
        static Ref<const ShaderAsset>    decode(const ShaderSpec&);
        
        //! Gets the name to the specified shader
        static std::string_view     name(const ShaderSpec&);
        
        //! Size of the compiled shader 
        virtual size_t      data_size() const override;
        
        //! Shader constructor
        ShaderAsset(ShaderType, Memory&&);

        //! Shader bytecode
        const Memory      payload;
        
        //! Shader type
        const ShaderType  type;
    
    private:
        //! Private destructor as these are considered load-once and keep until application exit
        virtual ~ShaderAsset();
    };
}
