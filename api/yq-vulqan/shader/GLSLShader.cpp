////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "GLSLShader.hpp"

#include <yq-toolbox/basic/ErrorDB.hpp>
#include <yq-toolbox/basic/DelayInit.hpp>
#include <yq-toolbox/io/Execute.hpp>
#include <yq-toolbox/io/FileUtils.hpp>
#include <yq-toolbox/text/chars.hpp>
#include <yq-vulqan/asset/AssetFactory.hpp>
#include <yq-vulqan/shader/Shader.hpp>

namespace yq::errors {
   using shader_compile_failure    = error_db::entry<"Shader failed to compile">;
   using shader_validate_failure   = error_db::entry<"Shader failed to validate">;
 }
    
namespace yq::tachyon::glsl {
    namespace {
        //  configuration to change/move
        std::filesystem::path   find_compiler()
        {
            const char* z   = getenv("VULKAN_SDK_PATH");
            if(!z)
                z   = "/usr";
        
            return std::filesystem::path(z) / "bin" / "glslc";
        }

        std::filesystem::path   find_validator()
        {
            const char* z   = getenv("VULKAN_SDK_PATH");
            if(!z)
                z   = "/usr";
        
            return std::filesystem::path(z) / "bin" / "glslangValidator";
        }
    }
    
    const std::filesystem::path&            compiler()
    {
        static std::filesystem::path s_ret = find_compiler();
        return s_ret;
    }
    
    const std::filesystem::path&            validator()
    {
        static std::filesystem::path s_ret = find_validator();
        return s_ret;
    }

    std::pair<ByteArray,std::error_code>    compile(const Source& src)
    {
        int                                 ecode   = -1;
        
        ProcessDescriptor   pd;
        pd.args.push_back(compiler().string());
        
        #if 0
        static const path_vector_t          dirs    = shader_dirs();
            // #include is a google extension...apparently (TODO, implement it)
        for(auto& d : dirs){
            pd.args.push_back("-I");
            pd.args.push_back(d.string());
        }
        #endif
        
        pd.args.push_back("--target-env=vulkan1.2");
        pd.args.push_back("-x");        // GLSL is the language of choice
        pd.args.push_back("glsl");
        
        pd.args.push_back("-O");        // optimize for performance!
        pd.args.push_back("-o");
        pd.args.push_back("-");

        const ByteArray* input                  = std::get_if<ByteArray>(&src);
        const std::filesystem::path*    ifile   = std::get_if<std::filesystem::path>(&src);
        
        ByteArray   capture;
        
        if(input){
            pd.args.push_back("-");
            capture = pd.execute(*input, nullptr, &ecode);
        } else if(ifile){
            pd.args.push_back(ifile->string());
            capture = pd.execute(ByteArray(), nullptr, &ecode);
        } else {
            return { ByteArray(), create_error<"Bad input source to GLSL shader compile">() };
        }

        if(ecode != 0)
            return { capture, create_error<"Shader failed to compile">() };
        return { capture, std::error_code() };
    }
    
    std::pair<ByteArray,std::error_code>    validate(const Source& src, ShaderType type)
    {
        int                                 ecode   = -1;

        ProcessDescriptor   pd;
        pd.args.push_back(validator().string());
        pd.args.push_back("--target-env");
        pd.args.push_back("vulkan1.2");
        
        #if 0
            // #include is a google extension...apparently (TODO, implement it)
        static const path_vector_t          dirs    = shader_dirs();
        for(auto& d : dirs){
            pd.args.push_back("-I" + d.string());
        }
        #endif
        
        const ByteArray* input                  = std::get_if<ByteArray>(&src);
        const std::filesystem::path*    ifile   = std::get_if<std::filesystem::path>(&src);
        
        ByteArray   capture;

        if(input){
            if(type == ShaderType())
                return { ByteArray(), create_error<"Bad shader type passed to GLSL validation">() };
            pd.args.push_back("--stdin");
            pd.args.push_back("-S");
            pd.args.push_back(to_lower(type.key()));
            pd.execute(*input, &capture, &ecode);
        } else if(ifile){
            pd.args.push_back(ifile->string());
            pd.execute(ByteArray(), &capture, &ecode);
        } else {
            return { ByteArray(), create_error<"Bad input source to GLSL shader validate">() };
        }

        if(ecode != 0)
            return { capture, errors::shader_validate_failure() };
        return { capture, std::error_code() };
    }

    ShaderType  shader_type(const std::filesystem::path& pth)
    {
        std::string             sspec   = pth.string();
        return ShaderType(file_extension(sspec));
    }
    
    namespace {
        void    reg_glsl()
        {
            Shader::cache().add_loader(
                { "vert", "tesc", "tese", "frag", "geom", "comp", "mesh", "task", "rgen", "rint", "rahit", "rchit", "rmiss", "rcall" },
                [](const std::filesystem::path&pth) -> Shader* 
                {
                    ShaderType  st  = shader_type(pth);
                    if(st == ShaderType())
                        throw create_error<"Bad file extension for a GLSL shader">();
                    auto [b,ec] = compile(pth);
                    if(ec)
                        throw ec;
                    return new Shader(st, Memory(COPY, b.data(), b.size()));
                }
            );
        }

        YQ_INVOKE(reg_glsl();)
    }
    
}
