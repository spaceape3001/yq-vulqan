////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SaveObject.hpp"
#include <yq/core/Object.hpp>
#include <yq/meta/PropertyInfo.hpp>
#include <yt/keywords.hpp>
#include <yt/tags.hpp>

namespace yq::tachyon {
    SaveObject::SaveObject(const Object& obj, uint64_t i) : m_info(&obj.metaInfo()), m_id(i)
    {
        for(const PropertyInfo* pi : m_info->properties(ALL).all){
            if(!pi->setter())   // it's read-only
                continue;
            if(!pi->tagged(kTag_Save))
                continue;
            any_x   val = pi->get(&obj);
            if(!val)
                continue;
            m_properties.push_back({ pi, std::move(*val) });
        }
    }
    
    SaveObject::SaveObject(std::string_view kType, uint64_t i) : m_info(ObjectInfo::find(kType)), m_id(i)
    {
        
    }
    
    SaveObject::~SaveObject()
    {
    }
    
    bool        SaveObject::valid() const
    {
        return m_info && m_id;
    }
}
