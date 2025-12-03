////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ObjectBuilder.hpp"
#include <yq/core/Object.hpp>

/*
    Random note: 43
    
    TBD: Widget & UI state for save/load.
*/

namespace yq::tachyon {
    ObjectBuilder::ObjectBuilder(const Object& obj) : m_meta(&obj.metaInfo()), m_metaName(m_meta->name())
    {
    }
    
    ObjectBuilder::ObjectBuilder(const ObjectSave& obj) : 
        m_meta(ObjectMeta::find(obj.type)), m_metaName(obj.type), m_properties(obj.properties)
    {
    }
    
    ObjectBuilder::~ObjectBuilder()
    {
    }
    
}
