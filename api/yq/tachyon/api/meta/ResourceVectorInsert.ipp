////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ResourceVectorInsert.hpp"
#include <yq/tachyon/api/meta/ResourceVectorProperty.hpp>
#include <cassert>

namespace yq::tachyon {
    ResourceVectorInsert::ResourceVectorInsert(ResourceVectorProperty* resourceProp, const std::source_location& sl) : Meta("insert", resourceProp, sl) 
    {
        assert(resourceProp);
        assert("no duplicate inserters!" && !resourceProp->m_insert);    //  duplicate property is an ERROR
        resourceProp->m_insert     = this;
    }

    const ResourceVectorProperty* ResourceVectorInsert::property() const
    {
        return static_cast<const ResourceVectorProperty*>(parent());
    }
}
