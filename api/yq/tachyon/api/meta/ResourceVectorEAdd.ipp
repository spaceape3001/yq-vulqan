////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ResourceVectorEAdd.hpp"
#include <yq/tachyon/api/meta/ResourceVectorProperty.hpp>
#include <cassert>

namespace yq::tachyon {
    ResourceVectorEAdd::ResourceVectorEAdd(ResourceVectorProperty* resourceProp, const std::source_location& sl) : Meta("add", resourceProp, sl) 
    {
        assert(resourceProp);
        assert("no duplicate adders!" && !resourceProp->m_eadd);    //  duplicate property is an ERROR
        resourceProp->m_eadd     = this;
    }

    const ResourceVectorProperty* ResourceVectorEAdd::property() const
    {
        return static_cast<const ResourceVectorProperty*>(parent());
    }
}
