////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ResourceVectorEmpty.hpp"
#include <yq/tachyon/api/meta/ResourceVectorProperty.hpp>
#include <cassert>

namespace yq::tachyon {
    ResourceVectorEmpty::ResourceVectorEmpty(ResourceVectorProperty* resourceProp, const std::source_location& sl) : Meta("empty", resourceProp, sl) 
    {
        assert(resourceProp);
        assert("no duplicate empties!" && !resourceProp->m_empty);    //  duplicate property is an ERROR
        resourceProp->m_empty     = this;
    }

    const ResourceVectorProperty* ResourceVectorEmpty::property() const
    {
        return static_cast<const ResourceVectorProperty*>(parent());
    }
}
