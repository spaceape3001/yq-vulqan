////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq-toolbox/basic/ErrorDB.hpp>
#include <yq-toolbox/basic/Object.hpp>
#include <yq-toolbox/basic/Ref.hpp>
#include <yq-toolbox/container/Set.hpp>
#include <yq-toolbox/text/IgCase.hpp>
#include <yq-toolbox/typedef/string_sets.hpp>
#include <yq-vulqan/asset/Asset.hpp>
#include <yq-vulqan/asset/AssetCache.hpp>
#include <functional>
#include <source_location>
#include <system_error>

namespace yq::tachyon {
    class Asset;
    class AssetInfo;
    
    namespace errors {
        using namespace yq::errors;
        using asset_saving_failed   = error_db::entry<"Unable to save asset">;
    }

    /*! \brief Basic asset factory
    
        This is an asset factory for a specific asset.
    */

    class AssetFactory : public AssetCache {
    public:
        const std::source_location&     source_location() const 
        { 
            return m_source; 
        }
        
    protected:
        friend class Asset;
        
        AssetFactory(const AssetInfo&, const std::source_location& sl);
        ~AssetFactory();

        //! Loads the specified file path (no resolution)
        Ref<const Asset>    _load(const std::filesystem::path&);
        
        //! Resolves & loads a partial path
        Ref<const Asset>    _pload(std::string_view);

        //! Resolves & finds a partial path
        Ref<const Asset>    _pfind(std::string_view) const;
    
        struct Loader;
        template <typename> struct TypedLoader;
        struct Saver;
        template <typename> struct TypedSaverBool;
        template <typename> struct TypedSaverError;
        
        std::vector<Loader*>        m_loaders;
        std::vector<Saver*>         m_savers;
        const AssetInfo*            m_asset;
    
    private:
        AssetFactory(const AssetFactory&) = delete;
        AssetFactory(AssetFactory&&) = delete;
        AssetFactory& operator=(const AssetFactory&) = delete;
        AssetFactory& operator=(AssetFactory&&) = delete;
        
        std::source_location        m_source;
    };
    
    /*! \brief Base loader
        
        This is a basic file loader
    */
    struct AssetFactory::Loader {
        //! This abstraction loads the data from a filesystem path
        virtual Asset*          load(const std::filesystem::path&) const = 0;
        StringSet               extensions;
        std::source_location    location;
        
        Loader(std::initializer_list<std::string_view> exts, const std::source_location& sl);
    };
    
    /*! \brief Specific asset loader
    
        This binds a specific function based loader to the base loader
    */
    template <typename A> 
    struct AssetFactory::TypedLoader : public Loader {
        using Function    = std::function<A*(const std::filesystem::path&)>;
        Function            fn;
        
        TypedLoader(Function f, std::initializer_list<std::string_view> exts, const std::source_location& sl) :
            Loader(exts, sl), fn(f) {}
        
        //! Adapter to load the resource
        A* load(const std::filesystem::path& p) const override
        {
            return fn(p);
        }
    };
    
    struct AssetFactory::Saver {
        virtual std::error_code save(const Asset&, const std::filesystem::path&) const = 0;
        StringSet               extensions;
        std::source_location    location;

        Saver(std::initializer_list<std::string_view> exts, const std::source_location& sl);
    };
    
    template <typename A>
    struct AssetFactory::TypedSaverBool : public Saver {
        using Function  = std::function<bool(const A&, const std::filesystem::path&)>;
        Function fn;
        TypedSaverBool(Function f, std::initializer_list<std::string_view> exts, const std::source_location& sl) :
            Saver(exts, sl), fn(f) {}
        
        virtual std::error_code save(const Asset& a, const std::filesystem::path& pth) const override
        {
            if(!fn(static_cast<const A&>(a), pth)){
                return errors::asset_saving_failed();
            }
            return {};
        }
    };
    
    template <typename A>
    struct AssetFactory::TypedSaverError : public Saver {
        using Function  = std::function<std::error_code(const A&, const std::filesystem::path&)>;
        Function fn;
        TypedSaverError(Function f, std::initializer_list<std::string_view> exts, const std::source_location& sl) :
            Saver(exts, sl), fn(f) {}
        
        virtual std::error_code            save(const Asset& a, const std::filesystem::path& pth) const override
        {
            return fn(static_cast<const A&>(a), pth);
        }
    };

    /*! \brief Specific factory
    
        This binds the specific asset type to the generic underlying asset factory
    */
    template <typename A>
    class TypedAssetFactory : public AssetFactory {
        friend A;
    public:
    
        using LoadFunction      = typename AssetFactory::TypedLoader<A>::Function;
        using SaveBoolFunction  = typename AssetFactory::TypedSaverBool<A>::Function;
        using SaveErrorFunction = typename AssetFactory::TypedSaverError<A>::Function;
    
        //! Gets the specific resource (by ID) from the cache (if already loaded)
        Ref<const A>    get(uint64_t i) const
        {
            return static_cast<const A*>(_find(i).ptr());
        }
    
        //! Gets the specific resource (resolved path) from the cache (if already loaded)
        Ref<const A>    getx(const std::filesystem::path&p) const
        {
            return static_cast<const A*>(_find(p).ptr());
        }
        
        //! Gets the specific resource (partial path) from the cache (if already loaded)
        Ref<const A>    get(std::string_view p) const
        {
            return static_cast<const A*>(_pfind(p).ptr());
        }
        
        //! Inserts a manually created resource into the factory
        void            insert(Ref<const A> a)
        {
            if(a)
                _insert(a.ptr());
        }

        //! Loads exact path (no resolution)
        Ref<const A>    loadx(const std::filesystem::path&p)
        {
            return static_cast<const A*>(_load(p).ptr());
        }
        
        //! Loads by resolving
        Ref<const A>    load(std::string_view p)
        {
            return static_cast<const A*>(_pload(p).ptr());
        }
        
        /*! \brief Adds a loader to the factory
        
            WARNING this is NOT thread-safe.  Do not call outside of startup-initialization!
        */
        void    add_loader(std::initializer_list<std::string_view> exts, LoadFunction fn, const std::source_location& sl=std::source_location::current())
        {
            m_loaders.push_back(new TypedLoader<A>(fn, exts, sl));
        }
        
        void    add_saver(std::initializer_list<std::string_view> exts, SaveBoolFunction fn, const std::source_location& sl=std::source_location::current())
        {
            m_savers.push_back(new TypedSaverBool<A>(fn, exts, sl));
        }
        
        void    add_saver(std::initializer_list<std::string_view> exts, SaveErrorFunction fn, const std::source_location& sl=std::source_location::current())
        {
            m_savers.push_back(new TypedSaverError<A>(fn, exts, sl));
        }

    private:
        TypedAssetFactory(const std::source_location& sl = std::source_location::current()) : AssetFactory(meta<A>(), sl)
        {
        }
    
    };
}
