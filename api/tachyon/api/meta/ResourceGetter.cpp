////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ResourceGetter.hpp"
#include <tachyon/api/meta/ResourceProperty.hpp>
#include <cassert>

namespace yq::tachyon {
    ResourceGetter::ResourceGetter(ResourceProperty* resourceProp, const std::source_location& sl) : Meta("get", resourceProp, sl) 
    {
        assert(resourceProp);
        assert("no duplicate getters!" && !resourceProp->m_getter);    //  duplicate property is an ERROR
        resourceProp->m_getter     = this;
    }

    const ResourceProperty* ResourceGetter::property() const
    {
        return static_cast<const ResourceProperty*>(parent());
    }
}
