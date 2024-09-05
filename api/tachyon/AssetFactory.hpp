////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/preamble.hpp>
#include <tachyon/Asset.hpp>
#include <tachyon/AssetCache.hpp>
#include <yq-toolbox/basic/Object.hpp>
#include <functional>

namespace yq::tachyon {

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
        
        std::vector<Loader*>        m_loaders;
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
    
    /*! \brief Specific factory
    
        This binds the specific asset type to the generic underlying asset factory
    */
    template <typename A>
    class TypedAssetFactory : public AssetFactory {
        friend A;
    public:
    
        using LoadFunction = typename AssetFactory::TypedLoader<A>::Function;
    
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
        void            add_loader(std::initializer_list<std::string_view> exts, LoadFunction fn, const std::source_location& sl=std::source_location::current())
        {
            m_loaders.push_back(new TypedLoader<A>(fn, exts, sl));
        }
        
    private:
        TypedAssetFactory(const std::source_location& sl = std::source_location::current()) : AssetFactory(meta<A>(), sl)
        {
        }
    
    };
}
