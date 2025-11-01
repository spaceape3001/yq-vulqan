////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SaveTachyon.hpp"
#include <yq/tachyon/api/Tachyon.hpp>
#include <yq/tachyon/api/Delegate.hpp>
#include <yq/resource/Resource.hpp>
#include <yq/tachyon/api/meta/ResourceProperty.hpp>
#include <yq/tachyon/api/meta/DelegateProperty.hpp>
#include <yq/tachyon/io/Save.hpp>

namespace yq::tachyon {
    SaveTachyon::SaveTachyon(Save& save, const Tachyon& tac) : SaveObject(save, tac, tac.id())
    {
        m_parent    = tac.parent();
        
        if(save.record_owners()){
            auto maybe  = save.std_thread(tac.owner());
            if(maybe){
                m_owner = *maybe;
            } else
                m_owner = tac.owner();
        }
        
        for(const ResourceProperty* aprops : tac.metaInfo().resources(ALL).all){
            ResourceCPtr   resource   = aprops->get(&tac);
            if(!resource)
                continue;
            m_resources.push_back({aprops, save.insert(*resource)});
        }
        
        for(const DelegateProperty* dprops : tac.metaInfo().delegates(ALL).all){
            DelegateCPtr    delegate = dprops->get(&tac);
            if(!delegate)
                continue;
            m_delegates.push_back({dprops, save.insert(*delegate)});
        }
        
        for(TypedID tid : tac.children())
            m_children.push_back(tid);
            
        m_progAttrs = tac.prog_attributes();
        m_userAttrs = tac.user_attributes();
    }
    
    SaveTachyon::SaveTachyon(Save& save, const TachyonMeta* info, uint64_t i) : SaveObject(save, info, i)
    {
    }
    
    SaveTachyon::~SaveTachyon()
    {
    }

    void        SaveTachyon::append(resource_t v)
    {
        if(v.info && v.resource)
            m_resources.push_back(v);
    }
    
    void        SaveTachyon::append(child_k, uint64_t v)
    {
        m_children.push_back(v);
    }

    void        SaveTachyon::append(delegate_t v)
    {
        if(v.info && v.delegate)
            m_delegates.push_back(v);
    }

    Any&               SaveTachyon::create_attribute(int k)
    {
        return m_progAttrs[k];
    }
    
    Any&               SaveTachyon::create_attribute(const std::string&k)
    {
        return m_userAttrs[k];
    }

    const TachyonMeta* SaveTachyon::info() const
    {
        return dynamic_cast<const TachyonMeta*>(SaveObject::info());
    }

    void    SaveTachyon::set_parent(uint64_t n)
    {
        m_parent    = n;
    }
    
    void    SaveTachyon::set_owner(owner_spec_t n)
    {
        m_owner = n;
    }

    bool    SaveTachyon::valid() const 
    {
        return info() && id();
    }
}
