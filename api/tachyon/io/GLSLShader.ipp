////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/io/GLSLShader.hpp>

#include <basic/errors.hpp>
#include <basic/DelayInit.hpp>
#include <basic/TextUtils.hpp>
#include <io/Execute.hpp>
#include <io/FileUtils.hpp>
#include <tachyon/errors.hpp>
#include <tachyon/AssetFactory.hpp>
#include <tachyon/Shader.hpp>

namespace yq {
    namespace tachyon {
        namespace glsl {
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
                    return { ByteArray(), errors::bad_argument() };
                }

                if(ecode != 0)
                    return { capture, errors::shader_compile_failure() };
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
                    pd.args.push_back("--stdin");
                    pd.args.push_back("-S");
                    pd.args.push_back(to_lower(type.key()));
                    pd.execute(*input, &capture, &ecode);
                } else if(ifile){
                    pd.args.push_back(ifile->string());
                    pd.execute(ByteArray(), &capture, &ecode);
                }

                if(ecode != 0)
                    return { capture, errors::shader_compile_failure() };
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
                                throw (std::error_code) errors::bad_extension();
                            auto [b,ec] = compile(pth);
                            if(ec)
                                throw ec;
                            return new Shader(b, st);
                        }
                    );
                }

                YQ_INVOKE(reg_glsl();)
            }
            
        }
    }
}
