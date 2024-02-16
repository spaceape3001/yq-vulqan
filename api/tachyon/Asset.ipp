////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/Asset.hpp>
#include <tachyon/AssetInfoWriter.hpp>
#include <0/basic/DelayInit.hpp>
#include <0/basic/TextUtils.hpp>
#include <0/io/FileResolver.hpp>
#include <YqEngineConfig.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::Asset)

namespace yq::tachyon {

    namespace {
        FileResolver    make_asset_search_path()
        {
            std::string_view        dd(build::data_directory());
            
            FileResolver    ret;
            vsplit(dd, ';', [&](std::string_view x){
                ret.add_path(dd);
            });
            return ret;
        }
    }

    //  If done, binary Cache will be SQLite based....

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    AssetInfo::AssetInfo(std::string_view zName, const ObjectInfo& base, const std::source_location& sl) :
        ObjectInfo(zName, base, sl)
    {
        set(Flag::ASSET);
    }
    

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////
    const FileResolver&      Asset::resolver()
    {
        static FileResolver ret = make_asset_search_path();
        return ret;
    }
    
    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    Asset::Asset()
    {
    }

    Asset::Asset(const std::filesystem::path&p) : m_filepath(p)
    {
    }
    
    Asset::~Asset()
    {
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    namespace {
        void    reg_asset()
        {
            [[maybe_unused]] auto res = writer<Asset>();
        }
        
        YQ_INVOKE(reg_asset();)
    }

}
