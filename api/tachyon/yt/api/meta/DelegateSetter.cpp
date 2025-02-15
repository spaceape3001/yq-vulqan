////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "DelegateSetter.hpp"
#include <yt/api/meta/DelegateProperty.hpp>
#include <cassert>

namespace yq::tachyon {
    DelegateSetter::DelegateSetter(DelegateProperty* delProp, const std::source_location& sl) : Meta("set", delProp, sl) 
    {
        assert(delProp);
        assert("no duplicate setters!" && !delProp->m_setter);    //  duplicate property is an ERROR
        delProp->m_setter     = this;
    }

    const DelegateProperty* DelegateSetter::property() const
    {
        return static_cast<const DelegateProperty*>(parent());
    }
}
