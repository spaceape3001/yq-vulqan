////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/core/Memory.hpp>
#include <yq/resource/Resource.hpp>
#include <tachyon/pipeline/ShaderType.hpp>
#include <tachyon/typedef/shader.hpp>

namespace yq::tachyon {

        //! Shader is a Vulkan compatible shader (compiled)
    class Shader : public Resource {
        YQ_RESOURCE_DECLARE(Shader, Resource)
    public:
    
        //! Decodes the specified shader
        static Ref<const Shader>    decode(const ShaderSpec&);
        
        //! Decodes the specified shader
        static Ref<const Shader>    decode(const ShaderSpec&, const ResourceLoadOptions&);
        
        //! Gets the name to the specified shader
        static std::string          name(const ShaderSpec&);
        
        //! Size of the compiled shader 
        virtual size_t      data_size() const override;
        
        //! Shader constructor
        Shader(ShaderType, Memory&&);

        //! Shader bytecode
        const Memory      payload;
        
        //! Shader type
        const ShaderType  type;
        
        static void init_meta();
    
    private:
        
        //! Private destructor as these are considered load-once and keep until application exit
        virtual ~Shader();
    };
}
