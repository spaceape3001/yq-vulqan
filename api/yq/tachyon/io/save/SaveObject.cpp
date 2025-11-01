////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SaveObject.hpp"
#include <yq/core/Object.hpp>
#include <yq/meta/PropertyMeta.hpp>
#include <yq/tachyon/tags.hpp>

namespace yq::tachyon {
    SaveObject::SaveObject(Save&save, const Object& obj, uint64_t i) : m_save(save), m_info(&obj.metaInfo()), m_id(i)
    {
        for(const PropertyMeta* pi : m_info->properties(ALL).all){
            if(!pi->setter())   // it's read-only
                continue;
            if(!pi->tagged(kTag_Save))
                continue;
            any_x   val = pi->get(&obj);
            if(!val)
                continue;
            m_properties.push_back({ pi, std::move(*val), pi->tagged(kTag_TachyonID) });
        }
    }
    
    SaveObject::SaveObject(Save& save, const ObjectMeta* kType, uint64_t i) : m_save(save), m_info(kType), m_id(i)
    {
        
    }

    SaveObject::~SaveObject()
    {
    }

    void    SaveObject::append(const SaveProperty& sp) 
    {
        m_properties.push_back(sp);
    }
    
    void    SaveObject::append(SaveProperty&&sp)
    {
        m_properties.push_back(std::move(sp));
    }
    
    size_t      SaveObject::count(property_k) const
    {
        return m_properties.size();
    }

    bool        SaveObject::valid() const
    {
        return m_info && m_id;
    }
}
