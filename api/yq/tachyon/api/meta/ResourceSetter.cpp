////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ResourceSetter.hpp"
#include <yq/tachyon/api/meta/ResourceProperty.hpp>
#include <cassert>

namespace yq::tachyon {
    ResourceSetter::ResourceSetter(ResourceProperty* resourceProp, const std::source_location& sl) : Meta("set", resourceProp, sl) 
    {
        assert(resourceProp);
        assert("no duplicate setters!" && !resourceProp->m_setter);    //  duplicate property is an ERROR
        resourceProp->m_setter     = this;
    }

    const ResourceProperty* ResourceSetter::property() const
    {
        return static_cast<const ResourceProperty*>(parent());
    }
}
