////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <filesystem>
#include <vector>
#include <yt/keywords.hpp>

namespace yq {
    class Object;
    class PropertyInfo;
    class Asset;
    class AssetInfo;
}

namespace yq::tachyon {

    class Delegate;
    class DelegateInfo;
    class Tachyon;
    class TachyonInfo;
    
    

    struct SaveAsset : public SaveObject {
        const AssetInfo*            assetInfo       = nullptr;
        std::filesystem::path       assetFile;
    };

    struct SaveDelegate : public SaveObject {
        const DelegateInfo*         delegateInfo    = nullptr;
    };

    class Save {
    public:
        struct object_t {
            std::vector<property_t> properties;
        };

        struct asset_t : public object_t {    // for loadable assets
            const AssetInfo*        info    = nullptr;
            std::filesystem::path   path;   // TBD
        };
    
        
        struct delegate_t : public object_t {
            const DelegateInfo*     info    = nullptr;
        };
        
        struct tachyon_t : public object_t {
            const TachyonInfo*      info    = nullptr;
            uint64_t                id      = 0ULL;
            std::vector<asset_t>    assets;
            std::vector<tachyon_t>  children;
            std::vector<delegate_t> delegates;
        };
        
        struct thread_t : public tachyon_t {
            std::vector<tachyon_t>  tachyons;
        };
        
        
        
        void    extract(asset_k, asset_t&, const Asset&);
        void    extract(delegate_k, delegate_t&, const Delegate&);
        void    extract(object_k, object_t&, const Object&);
        void    extract(tachyon_k, tachyon_t&, const Tachyon&, bool skipChildren=false);
        void    extract(thread_k, thread_t&, const Thread&);
    };
}

