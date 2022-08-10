////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "Asset.hpp"
#include "AssetCache.hpp"
#include <YqEngineConfig.hpp>
#include <basic/DelayInit.hpp>
#include <basic/DirUtils.hpp>

YQ_OBJECT_IMPLEMENT(yq::engine::Asset)
YQ_OBJECT_IMPLEMENT(yq::engine::AssetCache)
YQ_OBJECT_IMPLEMENT(yq::engine::AssetCompiler)
YQ_OBJECT_IMPLEMENT(yq::engine::AssetLoader)


namespace yq {
    namespace engine {
        namespace {
            path_vector_t               make_resource_search_path()
            {
                //  we'll make this fancier (later)
                path_vector_t   ret;
                ret.push_back(build::data_directory());
                return ret;
            }

            std::filesystem::path       make_binary_cache_root()
            {
                return "/tmp/yquill/.binary";
            }

        }

        
        //  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
        //  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

        AssetInfo::AssetInfo(std::string_view zName, const ObjectInfo& base, const std::source_location& sl) :
            MetaObjectInfo(zName, base, sl)
        {
            set_option(ASSET);
        }
        
        
        //  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

        const path_vector_t&             Asset::search_path()
        {
            static const path_vector_t sp = make_resource_search_path();
            return sp;
        }
        
        const std::filesystem::path&     Asset::binary_root()
        {
            static const std::filesystem::path  fp = make_binary_cache_root();
            return fp;
        }
        
        std::filesystem::path            Asset::resolve(const std::filesystem::path&p)
        {
            static path_vector_t  s_paths = search_path();
            if(p.is_absolute())
                return p;
                
            for(const auto& d : s_paths){
                std::filesystem::path   p2  = d / p;
                if(std::filesystem::exists(p2))
                    return p2;
            }
            
            return std::filesystem::absolute(p);    //  last test
        }
        
        std::filesystem::path            Asset::binary_path(const std::filesystem::path& p)
        {
            static const std::filesystem::path  b_cache = make_binary_cache_root();
            return b_cache.string() + p.string();
        }
        

        std::filesystem::path    Asset::search(const path_vector_t& paths, const std::filesystem::path& fp)
        {
            if(fp.is_absolute())
                return fp;
            std::filesystem::path   p2  = std::filesystem::absolute(fp);
            if(std::filesystem::exists(p2))
                return p2;
            for(auto& d : paths){
                p2  = d / fp;
                if(std::filesystem::exists(p2))
                    return p2;
            }
            return std::filesystem::path();
        }

        //  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

        Asset::Asset()
        {
        }
        
        Asset::~Asset()
        {
        }
        
        YQ_INVOKE(
            [[maybe_unused]] auto res = writer<Asset>();
        )


        //  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
        //  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

        AssetCacheInfo::AssetCacheInfo(std::string_view zName, const ObjectInfo& base, const std::source_location& sl) :
            ObjectInfo(zName, base, sl)
        {
            set_option(CACHE);
        }

        AssetCache::AssetCache(const AssetCacheInfo&)      // can't rely on the virtual working.....
        {
        }
        
        AssetCache::~AssetCache()
        {
        }

        /*
            DEFAULT BINARY location will be stored at /tmp/yquill/.binary, with the provided name tacked onto it.
            
            So, /home/user/foobar/mytexture.xpm -> /tmp/yquill/.binary/home/user/foobar/mytexture.xpm
        */

        Ref<Asset>          AssetCache::get(const std::filesystem::path& fp)
        {
            return Ref<Asset>();    // todo
        }
        
        Ref<Asset>          AssetCache::get(uint64_t i)
        {
            return Ref<Asset>();    // todo
        }

        //  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
        //  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

        AssetCompilerInfo::AssetCompilerInfo(std::string_view zName, const ObjectInfo& base, const std::source_location& sl) :
            ObjectInfo(zName, base, sl)
        {
            set_option(COMPILER);
        }

        //  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
        //  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

        AssetLoaderInfo::AssetLoaderInfo(std::string_view zName, const ObjectInfo& base, const std::source_location& sl) :
            ObjectInfo(zName, base, sl)
        {
            set_option(LOADER);
        }

        //  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;
        //  ;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;;

    }
}
