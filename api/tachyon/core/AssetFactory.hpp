////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/preamble.hpp>
#include <tachyon/core/Asset.hpp>
#include <tachyon/core/AssetCache.hpp>
#include <basic/Object.hpp>
#include <functional>

namespace yq::tachyon {
    class AssetFactory : public AssetCache {
    public:
        const std::source_location&     source_location() const 
        { 
            return m_source; 
        }
        
    protected:
        AssetFactory(const AssetInfo&, const std::source_location& sl);
        ~AssetFactory();

        //! Finds with a search

        Ref<const Asset>    _load(const std::filesystem::path&);
        Ref<const Asset>    _pload(std::string_view);
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
    
    struct AssetFactory::Loader {
        virtual Asset*          load(const std::filesystem::path&) const = 0;
        StringSet               extensions;
        std::source_location    location;
        
        Loader(std::initializer_list<std::string_view> exts, const std::source_location& sl);
    };
    
    template <typename A> 
    struct AssetFactory::TypedLoader : public Loader {
        using Function    = std::function<A*(const std::filesystem::path&)>;
        Function            fn;
        
        TypedLoader(Function f, std::initializer_list<std::string_view> exts, const std::source_location& sl) :
            Loader(exts, sl), fn(f) {}
        
        A* load(const std::filesystem::path& p) const override
        {
            return fn(p);
        }
    };
    
    template <typename A>
    class TypedAssetFactory : public AssetFactory {
        friend A;
    public:
    
        using LoadFunction = typename AssetFactory::TypedLoader<A>::Function;
    
        Ref<const A>    get(uint64_t i) const
        {
            return static_cast<const A*>(_find(i).ptr());
        }
    
        Ref<const A>    getx(const std::filesystem::path&p) const
        {
            return static_cast<const A*>(_find(p).ptr());
        }
        
        Ref<const A>    get(std::string_view p) const
        {
            return static_cast<const A*>(_pfind(p).ptr());
        }
        
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
