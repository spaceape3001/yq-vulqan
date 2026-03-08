////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ResourceVectorClear.hpp"
#include <yq/tachyon/api/meta/ResourceVectorProperty.hpp>
#include <cassert>

namespace yq::tachyon {
    ResourceVectorClear::ResourceVectorClear(ResourceVectorProperty* resourceProp, const std::source_location& sl) : Meta("clear", resourceProp, sl) 
    {
        assert(resourceProp);
        assert("no duplicate cleares!" && !resourceProp->m_clear);    //  duplicate property is an ERROR
        resourceProp->m_clear     = this;
    }

    const ResourceVectorProperty* ResourceVectorClear::property() const
    {
        return static_cast<const ResourceVectorProperty*>(parent());
    }
}
