////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ResourceVectorSetter.hpp"
#include <yq/tachyon/api/meta/ResourceVectorProperty.hpp>
#include <cassert>

namespace yq::tachyon {
    ResourceVectorSetter::ResourceVectorSetter(ResourceVectorProperty* resourceProp, const std::source_location& sl) : Meta("set", resourceProp, sl) 
    {
        assert(resourceProp);
        assert("no duplicate setters!" && !resourceProp->m_setter);    //  duplicate property is an ERROR
        resourceProp->m_setter     = this;
    }

    const ResourceVectorProperty* ResourceVectorSetter::property() const
    {
        return static_cast<const ResourceVectorProperty*>(parent());
    }
}
