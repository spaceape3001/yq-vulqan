////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Shader.hpp"

#include <basic/DelayInit.hpp>
#include <basic/Execute.hpp>
#include <basic/FileUtils.hpp>
#include <basic/Logging.hpp>
#include <basic/TextUtils.hpp>
#include <basic/meta/Init.hpp>

#include <YqEngineConfig.hpp>

#include <engine/AssetCache.hpp>
#include <engine/ResultCC.hpp>

#include <atomic>


namespace yq {
    namespace engine {

        namespace {
            //  configuration to change/move
            std::filesystem::path   glsl_compiler_executable()
            {
                const char* z   = getenv("VULKAN_SDK_PATH");
                if(!z)
                    z   = "/usr";
            
                return std::filesystem::path(z) / "bin" / "glslc";
            }

            std::filesystem::path   glsl_validator_executable()
            {
                const char* z   = getenv("VULKAN_SDK_PATH");
                if(!z)
                    z   = "/usr";
            
                return std::filesystem::path(z) / "bin" / "glslangValidator";
            }
            
            path_vector_t       shader_dirs()
            {
                path_vector_t   ret;
                ret.push_back( std::filesystem::path(build::data_directory()) / "shaders" );
                return ret;
            }
            
            ResultCC    compile_shader(const ByteArray& input, const std::filesystem::path& source, const std::filesystem::path& target, bool write_arg=false)
            {
                static const std::filesystem::path  glslc   = glsl_compiler_executable();
                int                                 ecode   = -1;
                
                ProcessDescriptor   pd;
                pd.args.push_back(glslc.string());
                
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
                if(target.empty()){
                    pd.args.push_back("-");
                } else {
                    pd.args.push_back(target.string());
                }
                
                if(source.empty()){
                    pd.args.push_back("-");
                } else {
                    pd.args.push_back(source.string());
                }
                
                if(write_arg)
                    yInfo() << "Compiling shader, command is: " << join(pd.args, " ");
                
                ResultCC    ret;
                ret.payload  = pd.execute(input, nullptr, &ecode);
                ret.good    = ecode == 0;
                if(!ret.good)
                    std::swap(ret.payload, ret.errors);
                
                return ret;
            }
            
            ResultCC    validate_shader(const ByteArray&input, const std::filesystem::path& source, ShaderType type)
            {
                static const std::filesystem::path  glslv   = glsl_validator_executable();
                int                                 ecode   = -1;

                ProcessDescriptor   pd;
                pd.args.push_back(glslv.string());
                pd.args.push_back("--target-env");
                pd.args.push_back("vulkan1.2");
                
                #if 0
                    // #include is a google extension...apparently (TODO, implement it)
                static const path_vector_t          dirs    = shader_dirs();
                for(auto& d : dirs){
                    pd.args.push_back("-I" + d.string());
                }
                #endif
                
                if(source.empty()){
                    pd.args.push_back("--stdin");
                    pd.args.push_back("-S");
                    pd.args.push_back(to_lower(type.key()));
                    
                } else {
                    pd.args.push_back(source.string());
                }

                ResultCC    ret;
                ret.payload = pd.execute(input, &ret.errors, &ecode);
                ret.good    = ecode == 0;
                return ret;
            }
        }


        ////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////
        class ShaderCache : public AssetCache {
            YQ_OBJECT_DECLARE(ShaderCache, AssetCache)
        public:
        
            static ShaderCache&     singleton();
            
            ShaderCPtr     get(const std::filesystem::path&);
            ShaderCPtr     get(uint64_t);
        
        protected:
            Ref<const Asset>      load_binary(const std::filesystem::path&) const override;
        
        private:
            ShaderCache();
            ~ShaderCache();
        };



        ////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////

        ShaderInfo::ShaderInfo(std::string_view zName, const AssetInfo& base, const std::source_location& sl) :
            AssetInfo(zName, base, sl)
        {
            set_option(SHADER);
        }


        ResultCC    Shader::compile(const std::filesystem::path& source, const std::filesystem::path& target, bool log_command)
        {
            return compile_shader(ByteArray(), source, target, log_command);
        }

        ResultCC    Shader::compile(const ByteArray& data, bool log_command)
        {
            return compile_shader(data, std::filesystem::path(), std::filesystem::path(), log_command);
        }
        

        const path_vector_t&       Shader::directories()
        {
            static const path_vector_t          dirs    = shader_dirs();
            return dirs;
        }

        ShaderCPtr    Shader::do_load(const std::filesystem::path&file, ShaderType st, unsigned int options)
        {
            if(st == ShaderType()){
                std::string             sspec   = file.string();
                bool                    ok  = false;
                st  = ShaderType(file_extension(sspec), &ok);
                if(!ok){
                    yError() << "Unable to deduce shader type from: " << file;
                    return ShaderCPtr();
                }
            }
            
            ByteArray   data;
            if(options & CC_SHADER){
                ResultCC    cc  = compile_shader(ByteArray(), file, std::filesystem::path(), static_cast<bool>(options & LOG_COMMAND));
                if(!cc.good){
                    yError() << "Unable to compile the shader: " << file << "\n" << cc.errors.as_view();
                    return ShaderCPtr();
                }
                
                data    = std::move(cc.payload);
            } else {
                data    = file_bytes(file);
                if(data.empty()){
                    yError() << "Unable to load the shader: " << file;
                    return ShaderCPtr();
                }
            }
            
            Ref<Shader>     ret = new Shader;
            ret->m_type = st;
            ret->m_payload  = std::move(data);
            ret->m_file     = file;
            ret->m_szt      = file_size_and_timestamp(file);
            return ret;
        }


        ShaderCPtr     Shader::get(const std::filesystem::path&fp)
        {
            return ShaderCache::singleton().get(fp);
        }
        
        ShaderCPtr     Shader::get(uint64_t i)
        {
            return ShaderCache::singleton().get(i);
        }

        ShaderCPtr      Shader::load(const std::filesystem::path& file)
        {
            std::filesystem::path   fspec    = search(file);
            if(fspec.empty()){
                yError() << "Unable to resolve the file: " << file;
                return ShaderCPtr();
            }
            
            return do_load(fspec, ShaderType(), true);
        }

        ShaderCPtr      Shader::load(const ByteArray& glsl, ShaderType st)
        {
            if(st == ShaderType()){
                yError() << "Cannot load shader as the type is unknown.";
                return ShaderCPtr();
            }
            
            ResultCC    cc  = compile_shader(glsl, std::filesystem::path(), std::filesystem::path());
            if(!cc.good){
                yError() << "Unable to compile the shader:\n" << cc.errors.as_view();
                return ShaderCPtr();
            }
            
            return new Shader(std::move(cc.payload), st);
        }

        std::filesystem::path    Shader::search(const std::filesystem::path& fp)
        {
            return Asset::search(directories(), fp);
        }

        ResultCC    Shader::validate(const std::filesystem::path& source)
        {
            return validate_shader(ByteArray(), source, ShaderType());
        }

        ResultCC    Shader::validate(const ByteArray& data, ShaderType st)
        {
            return validate_shader(data, std::filesystem::path(), st);
        }

        ////////////////////////////////////////////////////////////////////////////////

        Shader::Shader()
        {
        }
        
        Shader::Shader(const ByteArray&raw, ShaderType st) : m_payload(raw), m_type(st)
        {
            assert(m_type != ShaderType());
        }
        
        Shader::Shader(ByteArray&&raw, ShaderType st) : m_payload(std::move(raw)), m_type(st)
        {
            assert(m_type != ShaderType());
        }
        
        Shader::~Shader()
        {
        }

        size_t  Shader::data_size() const 
        {
            return m_payload.size();
        }

        bool    Shader::save_binary(const std::filesystem::path& fp) const 
        {
            return file_write(fp, m_payload);
        }

        ////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////


        ShaderCache&     ShaderCache::singleton()
        {
            static ShaderCache* s_singleton = new ShaderCache;
            return *s_singleton;
        }

        ////////////////////////////////////////////////////////////////////////////////

        ShaderCache::ShaderCache() : AssetCache(meta<ShaderCache>())
        {
        }
        
        ShaderCache::~ShaderCache()
        {
        }

        ShaderCPtr   ShaderCache::get(const std::filesystem::path& fp)
        {
            //  right now, hard-code to the manual method so we can bait & switch on the caching
            return Shader::load(fp);
        
            //Ref<const Asset>  ret = AssetCache::get(fp);
            //return ShaderCPtr(static_cast<const Shader*>(ret.ptr()));
        }
        
        ShaderCPtr   ShaderCache::get(uint64_t i)
        {
            Ref<const Asset>  ret = AssetCache::get(i);
            return ShaderCPtr(static_cast<const Shader*>(ret.ptr()));
        }

        Ref<const Asset>    ShaderCache::load_binary(const std::filesystem::path& fp) const
        {
            return Shader::do_load(fp, ShaderType(), false);
        }
        

        ////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////

        ShaderCompilerInfo::ShaderCompilerInfo(std::string_view zName, const AssetCompilerInfo& base, const std::source_location& sl) :
            AssetCompilerInfo(zName, base, sl)
        {
        }

        ////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////

        ShaderLoaderInfo::ShaderLoaderInfo(std::string_view zName, const AssetLoaderInfo& base, const std::source_location& sl) :
            AssetLoaderInfo(zName, base, sl)
        {
        }

        ////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////
        
        class GLSLCompiler : public ShaderCompiler {
            YQ_OBJECT_DECLARE(GLSLCompiler, ShaderCompiler)
        public:
            ResultCC   compile(const std::filesystem::path& source, const std::filesystem::path& target) const 
            {
                return compile_shader(ByteArray(), source, target);
            }
        };
        
        
        ////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////
        
        YQ_INVOKE(
            auto si = writer<Shader>();
            si.abstract();
            
            auto sca = writer<ShaderCache>();
            sca.abstract();
            sca.asset<Shader>();
            sca.compiler<ShaderCompiler>();
            sca.loader<ShaderLoader>();

            auto scc = writer<ShaderCompiler>();
            scc.abstract();

            auto sl = writer<ShaderLoader>();
            sl.abstract();
            
            auto glsl = writer<GLSLCompiler>();
            glsl.description("Shader compiler for GLSL language");
            glsl.extension("vert");
            glsl.extension("tesc");
            glsl.extension("tese");
            glsl.extension("frag");
            glsl.extension("geom");
            glsl.extension("comp");
            glsl.extension("mesh");
            glsl.extension("task");
            glsl.extension("rgen");
            glsl.extension("rint");
            glsl.extension("rahit");
            glsl.extension("rchit");
            glsl.extension("rmiss");
            glsl.extension("rcall");
        )
    }

}

YQ_OBJECT_IMPLEMENT(yq::engine::GLSLCompiler)
YQ_OBJECT_IMPLEMENT(yq::engine::Shader)
YQ_OBJECT_IMPLEMENT(yq::engine::ShaderCache)
YQ_OBJECT_IMPLEMENT(yq::engine::ShaderCompiler)
YQ_OBJECT_IMPLEMENT(yq::engine::ShaderLoader)
