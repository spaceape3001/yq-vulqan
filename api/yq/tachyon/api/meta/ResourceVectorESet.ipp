////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ResourceVectorESet.hpp"
#include <yq/tachyon/api/meta/ResourceVectorProperty.hpp>
#include <cassert>

namespace yq::tachyon {
    ResourceVectorESet::ResourceVectorESet(ResourceVectorProperty* resourceProp, const std::source_location& sl) : Meta("sget", resourceProp, sl) 
    {
        assert(resourceProp);
        assert("no duplicate esetters!" && !resourceProp->m_eset);    //  duplicate property is an ERROR
        resourceProp->m_eset     = this;
    }

    const ResourceVectorProperty* ResourceVectorESet::property() const
    {
        return static_cast<const ResourceVectorProperty*>(parent());
    }
}
