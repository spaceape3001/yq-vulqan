////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq-toolbox/basic/DelayInit.hpp>
#include <yq-toolbox/io/FileResolver.hpp>
#include <yq-toolbox/text/vsplit.hpp>
#include <yq-vulqan/asset/Asset.hpp>
#include <yq-vulqan/asset/AssetInfoWriter.hpp>
#include <yq-vulqan/config/build.hpp>

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

    static void    reg_asset()
    {
        auto w = writer<Asset>();
        w.description("Tachyon asset (ie texture, mesh, shader, etc)");
    }
        
    YQ_INVOKE(reg_asset();)

}
