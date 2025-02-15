////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/asset/Asset.hpp>

namespace yq::tachyon {
    class AssetProperty;

    /*! \brief Shim to add in sub-assets 
    */
    class ResourceInfo : public AssetInfo {
    public:
        template <typename C> class Writer;
        using AssetLUC      = MetaLookup<AssetProperty>;

        ResourceInfo(std::string_view zName, ObjectInfo& base, const std::source_location& sl=std::source_location::current());
 
        
    protected:

        virtual void    sweep_impl() override;

    private:
        friend class AssetProperty;
        
        struct {
            AssetLUC        all, local;
        }   m_assets;
    };
    
    /*! \brief Tachyon Resource
    
        Only reason for this class is to allow resources to have sub-assets/resources.
        
    */
    class Resource : public Asset {
        YQ_OBJECT_INFO(ResourceInfo)
        YQ_OBJECT_DECLARE(Resource, Asset)
    public:
    
        static void init_info();
        
    protected:
        Resource();
        Resource(const std::filesystem::path&);
        virtual ~Resource();

    };
}
