////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq-vulqan/logging.hpp>
#include <yq-vulqan/asset/Asset.hpp>
#include <yq-vulqan/asset/AssetFactory.hpp>
#include <yq-toolbox/io/FileResolver.hpp>
#include <yq-toolbox/io/FileUtils.hpp>
#include <filesystem>

namespace yq::tachyon {
    AssetFactory::AssetFactory(const AssetInfo&ai, const std::source_location& sl) : m_asset(&ai), m_source(sl)
    {
    }
    
    AssetFactory::~AssetFactory()
    {
    }

    Ref<const Asset>    AssetFactory::_load(const std::filesystem::path& fp, const AssetLoadOptions& options)
    {
        Ref<const Asset>  ret = _find(fp);
        if(ret)
            return ret;
            
        if(!std::filesystem::exists(fp)){
            tachyonInfo << "File does not exist (" << fp << ")";
            return nullptr;
        }

        std::string    x  = fp.extension().string();
        if(x.empty())      // no extension... abort
            return nullptr;
        x   = x.substr(1);
        
        Ref<Asset>  loaded  = nullptr;

        for(const Loader* l : m_loaders){
            if(!l->extensions.contains(x))
                continue;
            
            try {
                loaded     = l->load(fp, options);
            } 
            catch(std::error_code ec) {
                tachyonWarning << "Unable to load (" << fp << "): " << ec.message();
            }
            
            if(loaded)
                break;
        }
        
        if(!loaded)
            return nullptr;
            
        loaded -> m_filepath   = fp;
        _insert(loaded.ptr());
        return loaded;
    }
    
    Ref<const Asset>    AssetFactory::_pload(std::string_view pp, const AssetLoadOptions& options)
    {
        std::filesystem::path   fp   = Asset::resolver().resolve(pp);
        if(fp.empty()){
            tachyonWarning << "Unable to resolve to file: " << pp;
            return nullptr;
        }
        return _load(fp, options);
    }
    
    Ref<const Asset>    AssetFactory::_pfind(std::string_view pp) const
    {
        std::filesystem::path   fp   = Asset::resolver().resolve(pp);
        if(fp.empty())
            return nullptr;
        return _find(fp);
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    AssetFactory::Loader::Loader(std::initializer_list<std::string_view> exts, const std::source_location& sl)
    {
        for(auto x : exts)
            extensions << std::string(x);
        location    = sl;
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    AssetFactory::Saver::Saver(std::initializer_list<std::string_view> exts, const std::source_location& sl)
    {
        for(auto x : exts)
            extensions << std::string(x);
        location    = sl;
    }
}
