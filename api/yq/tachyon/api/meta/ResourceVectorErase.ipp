////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ResourceVectorErase.hpp"
#include <yq/tachyon/api/meta/ResourceVectorProperty.hpp>
#include <cassert>

namespace yq::tachyon {
    ResourceVectorErase::ResourceVectorErase(ResourceVectorProperty* resourceProp, const std::source_location& sl) : Meta("erase", resourceProp, sl) 
    {
        assert(resourceProp);
        assert("no duplicate erasers!" && !resourceProp->m_erase);    //  duplicate property is an ERROR
        resourceProp->m_erase     = this;
    }

    const ResourceVectorProperty* ResourceVectorErase::property() const
    {
        return static_cast<const ResourceVectorProperty*>(parent());
    }
}
