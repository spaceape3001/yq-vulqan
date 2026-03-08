////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ResourceVectorAppend.hpp"
#include <yq/tachyon/api/meta/ResourceVectorProperty.hpp>
#include <cassert>

namespace yq::tachyon {
    ResourceVectorAppend::ResourceVectorAppend(ResourceVectorProperty* resourceProp, const std::source_location& sl) : Meta("append", resourceProp, sl) 
    {
        assert(resourceProp);
        assert("no duplicate appenders!" && !resourceProp->m_append);    //  duplicate property is an ERROR
        resourceProp->m_append     = this;
    }

    const ResourceVectorProperty* ResourceVectorAppend::property() const
    {
        return static_cast<const ResourceVectorProperty*>(parent());
    }
}
