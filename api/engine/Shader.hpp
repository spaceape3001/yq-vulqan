////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <engine/Asset.hpp>
#include <engine/preamble.hpp>
#include <basic/ByteArray.hpp>

namespace yq {
    namespace engine {
        class Shader;
        class ShaderCompiler;
        class ShaderLoader;
        class ShaderCache;
        struct ResultCC;

        
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        
        class ShaderInfo : public AssetInfo {
        public:
            template <typename C> class Writer;

            ShaderInfo(std::string_view zName, const AssetInfo& base, const std::source_location& sl=std::source_location::current());
            
        protected:
        };

            //! Shader is a Vulkan compatible shader (compiled)
        class Shader : public Asset {
            YQ_OBJECT_DECLARE(Shader, Asset)
        public:
        

            /*! \brief Compiles a shader
            
                This compiles a shader, from the specified file, into the target.
                
                \param[in]  source      File path to the source
                \param[in]  target      File path to the target location (leave blank to return as payload)
                \param[in]  log_command True to enable writing command to info logger
            */
            static ResultCC     compile(const std::filesystem::path& source, const std::filesystem::path& target=std::filesystem::path(), bool log_command=false);

            /*! \brief Compiles a shader
            
                This compiles a shader from into the result's payload.
                
                \param[in] glslData     This is the GLSL shader data.
            */
            static ResultCC     compile(const ByteArray& glslData, bool log_command=false);

            //!  All shader directories...
            static const path_vector_t&   directories();

            //!  Gets or loads specified shader
            static ShaderCPtr      get(const std::filesystem::path&);

            //!  Gets specified shader
            static ShaderCPtr      get(uint64_t);
            
            /*! \brief Compiles & Loads shader
            
                This compiles and loads the shaders (bypassing the cache).
            */
            static ShaderCPtr      load(const std::filesystem::path&);

            /*! \brief Compiles & Loads shader
            
                This compiles and loads the shaders (bypassing the cache).
            */
            static ShaderCPtr      load(const ByteArray& glsl, ShaderType);
            
            /*! \brief Searches for a shader
            
                This searches the shader directories for the given filespec.
                1) Absolute will be returned immediately.
                2) Resolved against current working directory
                3) Resolved using the directories(), in order
                
                \return EMPTY if no existing file is found matching the provided criteria.
            */
            static std::filesystem::path    search(const std::filesystem::path&);

            /*! \brief Validates a shader
            
                This validates a shader (from file).
                \param[in]  source File path to the source
            */
            static ResultCC         validate(const std::filesystem::path& source);

            /*! \brief Validates a shader
            
                This validates a shader (from memory).

                \param[in] glslData     This is the GLSL shader data.
            */
            static ResultCC         validate(const ByteArray& glslData, ShaderType);

        
                //  ---------------------------------------------------------------
        
            Shader(const ByteArray&, ShaderType);
            Shader(ByteArray&&, ShaderType);
            virtual ~Shader();

            /*! \brief Filename
            
                This will be empty for direct load (ie, compiled/set from data)
            */
            const std::filesystem::path&    file() const { return m_file; }
            
            //! File information at last load
            const SizeTimestamp&            file_szt() const { return m_szt; }
            
            const ByteArray&                payload() const { return m_payload; }
            virtual size_t                  data_size() const override;
            virtual bool                    save_binary(const std::filesystem::path&) const override;
        
            ShaderType                      shader_type() const { return m_type; }
        
        
        private:
            friend class ShaderCache;

            Shader();
            
            //! Raw load (from absolute file)
            static ShaderCPtr      do_load(const std::filesystem::path&, ShaderType st, unsigned int options);

            enum {
                //! Compiles the shader
                CC_SHADER           = 0x1,
                
                //! Dumps the command line being attempted
                LOG_COMMAND         = 0x2
            };

            ByteArray               m_payload;
            ShaderType              m_type;
            std::filesystem::path   m_file;
            SizeTimestamp           m_szt;
        };

        template <typename C>
        class ShaderInfo::Writer : public AssetInfo::Writer<C> {
        public:
            Writer(ShaderInfo* shaderInfo) : AssetInfo::Writer<C>(shaderInfo)
            {
            }
            
            Writer(ShaderInfo& shaderInfo) : Writer(&shaderInfo)
            {
            }
        };


        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        class ShaderCompilerInfo : public AssetCompilerInfo {
        public:
            template <typename C> class Writer;

            ShaderCompilerInfo(std::string_view zName, const AssetCompilerInfo& base, const std::source_location& sl=std::source_location::current());

        protected:
        };
        
        class ShaderCompiler : public AssetCompiler {
            YQ_OBJECT_INFO(ShaderCompilerInfo)
            YQ_OBJECT_DECLARE(ShaderCompiler, AssetCompiler)
        public:

        };

        template <typename C>
        class ShaderCompilerInfo::Writer : public AssetCompilerInfo::Writer<C> {
        public:
            Writer(ShaderCompilerInfo* shaderCompilerInfo) : AssetCompilerInfo::Writer<C>(shaderCompilerInfo)
            {
            }
            
            Writer(ShaderCompilerInfo& shaderCompilerInfo) : Writer(&shaderCompilerInfo)
            {
            }
        };
        
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        
        class ShaderLoaderInfo : public AssetLoaderInfo {
        public:
            template <typename C> class Writer;

            ShaderLoaderInfo(std::string_view zName, const AssetLoaderInfo& base, const std::source_location& sl=std::source_location::current());

        protected:
        };
        
        class ShaderLoader : public AssetLoader {
            YQ_OBJECT_INFO(ShaderLoaderInfo)
            YQ_OBJECT_DECLARE(ShaderLoader, AssetLoader)
        public:
        };

        template <typename C>
        class ShaderLoaderInfo::Writer : public AssetLoaderInfo::Writer<C> {
        public:
            Writer(ShaderLoaderInfo* shaderLoaderInfo) : AssetLoaderInfo::Writer<C>(shaderLoaderInfo)
            {
            }
            
            Writer(ShaderLoaderInfo& shaderLoaderInfo) : Writer(&shaderLoaderInfo)
            {
            }
        };
   }
}
