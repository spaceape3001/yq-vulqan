////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ResourceVectorGetter.hpp"
#include <yq/tachyon/api/meta/ResourceVectorProperty.hpp>
#include <cassert>

namespace yq::tachyon {
    ResourceVectorGetter::ResourceVectorGetter(ResourceVectorProperty* resourceProp, const std::source_location& sl) : Meta("get", resourceProp, sl) 
    {
        assert(resourceProp);
        assert("no duplicate getters!" && !resourceProp->m_getter);    //  duplicate property is an ERROR
        resourceProp->m_getter     = this;
    }

    const ResourceVectorProperty* ResourceVectorGetter::property() const
    {
        return static_cast<const ResourceVectorProperty*>(parent());
    }
}
