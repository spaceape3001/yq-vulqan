////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SaveTachyon.hpp"
#include <yt/api/Tachyon.hpp>
#include <yt/api/Delegate.hpp>
#include <yq/asset/Asset.hpp>
#include <yt/api/meta/AssetProperty.hpp>
#include <yt/api/meta/DelegateProperty.hpp>
#include <yt/io/Save.hpp>

namespace yq::tachyon {
    SaveTachyon::SaveTachyon(Save& save, const Tachyon& tac) : SaveObject(save, tac, tac.id())
    {
        for(const AssetProperty* aprops : tac.metaInfo().assets(ALL).all){
            AssetCPtr   asset   = aprops->get(&tac);
            if(!asset)
                continue;
            m_assets.push_back({aprops, save.insert(*asset)});
        }
        
        for(const DelegateProperty* dprops : tac.metaInfo().delegates(ALL).all){
            DelegateCPtr    delegate = dprops->get(&tac);
            if(!delegate)
                continue;
            m_delegates.push_back({dprops, save.insert(*delegate)});
        }
    }
    
    SaveTachyon::SaveTachyon(Save& save, const TachyonInfo* info, uint64_t i) : SaveObject(save, info, i)
    {
    }
    
    SaveTachyon::~SaveTachyon()
    {
    }

    const TachyonInfo* SaveTachyon::info() const
    {
        return dynamic_cast<const TachyonInfo*>(SaveObject::info());
    }

    bool    SaveTachyon::valid() const 
    {
        return info() && id();
    }
}
