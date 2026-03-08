////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ResourceVectorEGet.hpp"
#include <yq/tachyon/api/meta/ResourceVectorProperty.hpp>
#include <cassert>

namespace yq::tachyon {
    ResourceVectorEGet::ResourceVectorEGet(ResourceVectorProperty* resourceProp, const std::source_location& sl) : Meta("eget", resourceProp, sl) 
    {
        assert(resourceProp);
        assert("no duplicate egetters!" && !resourceProp->m_eget);    //  duplicate property is an ERROR
        resourceProp->m_eget     = this;
    }

    const ResourceVectorProperty* ResourceVectorEGet::property() const
    {
        return static_cast<const ResourceVectorProperty*>(parent());
    }
}
