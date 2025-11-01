////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "DelegateGetter.hpp"
#include <yq/tachyon/api/meta/DelegateProperty.hpp>
#include <cassert>

namespace yq::tachyon {
    DelegateGetter::DelegateGetter(DelegateProperty* delegateProp, const std::source_location& sl) : Meta("get", delegateProp, sl) 
    {
        assert(delegateProp);
        assert("no duplicate getters!" && !delegateProp->m_getter);    //  duplicate property is an ERROR
        delegateProp->m_getter     = this;
    }

    const DelegateProperty* DelegateGetter::property() const
    {
        return static_cast<const DelegateProperty*>(parent());
    }
}
