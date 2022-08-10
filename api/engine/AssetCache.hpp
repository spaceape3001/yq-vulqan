////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "Asset.hpp"
#include <filesystem>
#include <tbb/spin_rw_mutex.h>

namespace yq {
    namespace engine {
        class Asset;
        class AssetCompiler;
        class AssetCompilerInfo;
        class AssetInfo;
        class AssetLoader;
        class AssetLoaderInfo;
        
        class AssetCache;
        
        
        class AssetCacheInfo : public ObjectInfo {
        public:
            template <typename C> class Writer;

            AssetCacheInfo(std::string_view zName, const ObjectInfo& base, const std::source_location& sl=std::source_location::current());

        protected:
        
            const AssetInfo*            base_asset() const { return m_asset; }
            const AssetCompilerInfo*    base_compiler() const { return m_compiler; }
            const AssetLoaderInfo*      base_loader() const { return m_loader; }
        
        private:
            const AssetInfo*            m_asset     = nullptr;
            const AssetCompilerInfo*    m_compiler  = nullptr;
            const AssetLoaderInfo*      m_loader    = nullptr;
        };
        
        /*! \brief An asset cache retains the data
        
            Most all engine components will query the cache for the data, if not present, loads it.  (Compiling first, if necessary)
        */
        class AssetCache : public Object, trait::not_copyable, trait::not_moveable {
            YQ_OBJECT_INFO(AssetCacheInfo)
            YQ_OBJECT_DECLARE(AssetCache, Object)
        public:
        
        
        
            //  TODO.....

        protected:
            Ref<Asset>          get(const std::filesystem::path&);
            Ref<Asset>          get(uint64_t);


            AssetCache(const AssetCacheInfo&);      // can't rely on the virtual working.....
            ~AssetCache();

            virtual Ref<const Asset>  load_binary(const std::filesystem::path&) const = 0;
            
        private:
            std::vector<const AssetInfo*>       m_assetInfos;
            std::vector<const AssetLoader*>     m_assetLoaders;
            std::vector<const AssetCompiler*>   m_assetCompilers;

            mutable tbb::spin_rw_mutex          m_mutex;
            std::map<std::filesystem::path, Ref<const Asset>>   m_cache;
        };


        template <typename C>
        class AssetCacheInfo::Writer : public ObjectInfo::Writer<C> {
        public:
            Writer(AssetCacheInfo* assetCacheInfo) : ObjectInfo::Writer<C>(assetCacheInfo)
            {
            }
            
            Writer(AssetCacheInfo& assetCacheInfo) : Writer(&assetCacheInfo)
            {
            }
            
            Writer&     asset(const AssetInfo& ai)
            {
                AssetCacheInfo* aci = static_cast<AssetCacheInfo*>(Meta::Writer::m_meta);
                if(aci)
                    aci -> m_asset  = &ai;
                return *this;
            }
            
            template <typename A>
            Writer&     asset()
            {
                asset(meta<A>());
                return *this;
            }
            
            Writer&     compiler(const AssetCompilerInfo&ai)
            {
                AssetCacheInfo* aci = static_cast<AssetCacheInfo*>(Meta::Writer::m_meta);
                if(aci)
                    aci -> m_compiler = &ai;
                return *this;
            }
            
            
            template <typename A>
            Writer&     compiler()
            {
                compiler(meta<A>());
                return *this;
            }
            
            Writer& loader(const AssetLoaderInfo& ali)
            {
                AssetCacheInfo* aci = static_cast<AssetCacheInfo*>(Meta::Writer::m_meta);
                if(aci)
                    aci -> m_loader = &ali;
                return *this;
            }
            
            template <typename A>
            Writer&     loader()
            {
                loader(meta<A>());
                return *this;
            }
        };
    }
}
