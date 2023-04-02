////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/TachyonLog.hpp>
#include <tachyon/asset/Asset.hpp>
#include <tachyon/asset/AssetFactory.hpp>
#include <io/FileResolver.hpp>
#include <io/FileUtils.hpp>

namespace yq {
    namespace tachyon {


        AssetFactory::AssetFactory(const AssetInfo&ai, const std::source_location& sl) : m_asset(&ai), m_source(sl)
        {
        }
        
        AssetFactory::~AssetFactory()
        {
        }

        const Asset*    AssetFactory::_load(const std::filesystem::path& fp)
        {
            const Asset*    ret = _find(fp);
            if(ret)
                return ret;
            if(!std::filesystem::exists(fp))
                return nullptr;

            std::string    x  = fp.extension().string();
            if(x.empty())       // no extension... abort
                return nullptr;
            x   = x.substr(1);
            
            Asset*  loaded  = nullptr;

            for(const Loader* l : m_loaders){
                if(!l->extensions.contains(x))
                    continue;
                
                try {
                    loaded     = l->load(fp);
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
                
            const Asset*    prev    = _insert(loaded);
            if(prev){
                delete loaded;
                return prev;
            } else
                return loaded;
        }
        
        const Asset*    AssetFactory::_pload(std::string_view pp)
        {
            std::filesystem::path   fp   = Asset::resolver().resolve(pp);
            if(fp.empty())
                return nullptr;
            return _load(fp);
        }
        
        const Asset*    AssetFactory::_pfind(std::string_view pp) const
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

    }
}
