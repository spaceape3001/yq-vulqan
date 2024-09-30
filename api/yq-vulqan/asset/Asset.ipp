////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <yq-toolbox/errors.hpp>
#include <yq-toolbox/basic/DelayInit.hpp>
#include <yq-toolbox/io/FileUtils.hpp>
#include <yq-toolbox/io/FileResolver.hpp>
#include <yq-toolbox/text/vsplit.hpp>

#include <yq-vulqan/logging.hpp>
#include <yq-vulqan/asset/Asset.hpp>
#include <yq-vulqan/asset/AssetFactory.hpp>
#include <yq-vulqan/asset/AssetInfoWriter.hpp>
#include <yq-vulqan/config/build.hpp>
#include <unistd.h>

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
    
    std::filesystem::path    Asset::resolve(std::string_view x)
    {
        return resolver().resolve(x);
    }
    
    std::filesystem::path    Asset::resolve(full_t, std::string_view x)
    {
        return resolver().resolve(x);
    }
    
    std::filesystem::path    Asset::resolve(partial_t, std::string_view x)
    {
        return resolver().partial(x);
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
    
    namespace errors {
        using filepath_existing             = error_db::entry<"Filepath already exists">;
        using no_file_extension             = error_db::entry<"No file extension provided to file">;
        using invalid_collision_strategy    = error_db::entry<"File collision strategy is invalid">;
        using no_savers_defined             = error_db::entry<"Asset class has NO saving functions defined">;
        using no_savers_applicable          = error_db::entry<"No file savers defined for given output">;
        using saving_exception              = error_db::entry<"Exception thrown during saving">;
    }

    std::error_code Asset::save_to(const std::filesystem::path& fp, const SaveOptions& options) const
    {
        if(fp.empty())
            return errors::filepath_empty();
            
        AssetFactory&   af = factory();
        if(af.m_savers.empty()){
            return errors::no_savers_defined();
        }
        
        std::string    x  = fp.extension().string();
        if(x.empty())      // no extension... abort
            return errors::no_file_extension();
        x   = x.substr(1);
        if(x.empty())      // no extension... abort
            return errors::no_file_extension();
        
        std::filesystem::path   save_file;
        bool    existing    = std::filesystem::exists(fp);
        if(existing){
            switch(options.collision){
            case FileCollisionStrategy::Abort:
                return errors::filepath_existing();
            case FileCollisionStrategy::Overwrite:
            case FileCollisionStrategy::Backup:
                save_file   = fp.string() + "~tmp";
                break;
            default:
                return errors::invalid_collision_strategy();
            }
        } else {
            save_file   = fp;
        }
        
        std::error_code     ec = errors::no_savers_applicable();
        
        for(const AssetFactory::Saver* s : af.m_savers){
            if(!s->extensions.contains(x))
                continue;
            try {
                ec  = s -> save(*this, save_file);
                if(ec != std::error_code())
                    continue;
                break;
            }
            catch(std::error_code ec2)
            {
                ec2 = ec;
            }
            #ifndef NDEBUG
            catch(...)
            {
                ec  = errors::saving_exception();
            }
            #endif
        }
        
        if(ec != std::error_code()){
            assetWarning << "Unable to save to file " << save_file << " (" << ec.message() << ")";
            return ec;
        }
        
        if(existing){
            if(options.collision == FileCollisionStrategy::Backup){
                file_backup(fp.c_str());
            }
            rename(save_file.c_str(), fp.c_str());
        }
        
        if(options.set_name && (fp != m_filepath) && !af.contains(id())){
            const_cast<Asset*>(this) -> m_filepath  = fp;
        }

        return {};
    }

    ////////////////////////////////////////////////////////////////////////////////////////////////////////////////

    static void    reg_asset()
    {
        auto w = writer<Asset>();
        w.description("Tachyon asset (ie texture, mesh, shader, etc)");
    }
        
    YQ_INVOKE(reg_asset();)

}
