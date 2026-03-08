////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ResourceVectorCount.hpp"
#include <yq/tachyon/api/meta/ResourceVectorProperty.hpp>
#include <cassert>

namespace yq::tachyon {
    ResourceVectorCount::ResourceVectorCount(ResourceVectorProperty* resourceProp, const std::source_location& sl) : Meta("clear", resourceProp, sl) 
    {
        assert(resourceProp);
        assert("no duplicate counters!" && !resourceProp->m_count);    //  duplicate property is an ERROR
        resourceProp->m_count     = this;
    }

    const ResourceVectorProperty* ResourceVectorCount::property() const
    {
        return static_cast<const ResourceVectorProperty*>(parent());
    }
}
