////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <basic/MetaObject.hpp>
#include <basic/Ref.hpp>
#include <basic/Set.hpp>
#include <basic/SizeTimestamp.hpp>
#include <basic/UniqueID.hpp>

#include <engine/preamble.hpp>

#include <filesystem>

namespace yq {
    namespace engine {
        class Asset;
        class AssetInfo;
        class AssetLoader;
        class AssetCache;
        
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        class AssetInfo : public MetaObjectInfo {
        public:
            template <typename C> class Writer;

            AssetInfo(std::string_view zName, const ObjectInfo& base, const std::source_location& sl=std::source_location::current());
            
            //! Loads the asset from native binary format (whatever that is)
            //virtual Ref<Asset>  load_binary(const std::filesystem::path&) { return nullptr; }
            
        protected:
        };
        
        /*! \brief An asset of the graphics engine
        
            An asset (here) is something that can be loaded by the engine, and used in some predefined fashion.  
            (ie, texture, shader, sounds, etc)  Which is why the asset-library also exists, predefined cameras & shapes
        */
        class Asset : public MetaObject {
            YQ_OBJECT_INFO(AssetInfo)
            YQ_OBJECT_DECLARE(Asset, MetaObject)
        public:
            virtual size_t      data_size() const = 0;
            
            //! Saves data to native binary format (whatever that is)
            virtual bool        save_binary(const std::filesystem::path&) const = 0;
            
            static const path_vector_t&             search_path();
            static const std::filesystem::path&     binary_root();
            static std::filesystem::path            resolve(const std::filesystem::path&);
            static std::filesystem::path            binary_path(const std::filesystem::path&);
            
            /*! Searches the given vector for the specified file
            
                \note An ABSOLUTE file will auto-return itself.
                
                This first checks the relative against the current working directory, returns if that file exists.
                Otherwise, it'll march through the paths, doing the same check.
            
                \param[in]  paths   Directories to search
                \param[in]  file    Given filepath
                \return filepath if absolute or detected, empty otherwise
            */
            static std::filesystem::path            search(const path_vector_t& paths, const std::filesystem::path& file);
        
        protected:
            Asset();
            virtual ~Asset();
        };

        template <typename C>
        class AssetInfo::Writer : public MetaObjectInfo::Writer<C> {
        public:
            Writer(AssetInfo* assetInfo) : MetaObjectInfo::Writer<C>(assetInfo)
            {
            }
            
            Writer(AssetInfo& assetInfo) : Writer(&assetInfo)
            {
            }
        };
        
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        
        class AssetCompilerInfo : public ObjectInfo {
        public:
            template <typename C> class Writer;

            AssetCompilerInfo(std::string_view zName, const ObjectInfo& base, const std::source_location& sl=std::source_location::current());

            const StringSet&    extensions() const { return m_extensions; }

        protected:
            StringSet   m_extensions;
        };

        /*! \brief Compiler of asset
        
            An asset compiler is one that can convert a given resource into the internal representation
            within a file (instead of memory.  When a loader & compiler both claim ownership to 
            file extensions, the compiler will be given preference for FILE to FILE conversions.
        */
        class AssetCompiler : public Object {
            YQ_OBJECT_INFO(AssetCompilerInfo)
            YQ_OBJECT_DECLARE(AssetCompiler, Object)
        public:
        
            /*! \brief "Compiles" the asset
            
                This compiles the asset into a file of the native format.
                
                \param[in]  Source filename (should be resolved & absolute)
                \param[in]  Target filename (should be resolved & absolute), or EMPTY to cause product to return in payload.
            */
            virtual ResultCC    compile(const std::filesystem::path& source, const std::filesystem::path& target) const = 0;
        };

        template <typename C>
        class AssetCompilerInfo::Writer : public ObjectInfo::Writer<C> {
        public:
            Writer& extension(std::string_view v)
            {
                AssetCompilerInfo*     ali = static_cast<AssetCompilerInfo*>(Meta::Writer::m_meta);
                if(ali)
                    ali -> m_extensions.insert(std::string(v));
                return *this;
            }

            Writer(AssetCompilerInfo* assetCompilerInfo) : ObjectInfo::Writer<C>(assetCompilerInfo)
            {
            }
            
            Writer(AssetCompilerInfo& assetCompilerInfo) : Writer(&assetCompilerInfo)
            {
            }
        };


        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

        class AssetLoaderInfo : public ObjectInfo {
        public:
            template <typename C> class Writer;

            AssetLoaderInfo(std::string_view zName, const ObjectInfo& base, const std::source_location& sl=std::source_location::current());

            const StringSet&    extensions() const { return m_extensions; }

        protected:
            StringSet   m_extensions;
            
        };

        /*! \brief A loader LOADS an asset
        
            This function LOADS an asset from file into INTERNAL memory
        */
        class AssetLoader : public Object {
            YQ_OBJECT_INFO(AssetLoaderInfo)
            YQ_OBJECT_DECLARE(AssetLoader, Object)
        public:
        
            virtual Ref<Asset>      load_asset(const std::filesystem::path&) const = 0;
        };
        
        template <typename C>
        class AssetLoaderInfo::Writer : public ObjectInfo::Writer<C> {
        public:
            Writer& extension(std::string_view v)
            {
                AssetLoaderInfo*     ali = static_cast<AssetLoaderInfo*>(Meta::Writer::m_meta);
                if(ali)
                    ali -> m_extensions.insert(std::string(v));
                return *this;
            }
        
        
            Writer(AssetLoaderInfo* assetLoaderInfo) : ObjectInfo::Writer<C>(assetLoaderInfo)
            {
            }
            
            Writer(AssetLoaderInfo& assetLoaderInfo) : Writer(&assetLoaderInfo)
            {
            }
        };        

        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
        ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    }
}
