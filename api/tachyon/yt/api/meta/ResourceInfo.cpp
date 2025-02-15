////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ResourceInfo.hpp"
#include "AssetProperty.hpp"

namespace yq::tachyon {
    ResourceInfo::ResourceInfo(std::string_view zName, ObjectInfo& base, const std::source_location& sl) : 
        AssetInfo(zName, base, sl)
    {
    }

    void    ResourceInfo::sweep_impl() 
    {
        AssetInfo::sweep_impl();
        m_assets.all.clear();
        m_assets.all += m_assets.local;
        if(const ResourceInfo* p = dynamic_cast<const ResourceInfo*>(base())){
            m_assets.all += p->m_assets.all;
        }
    }
}
