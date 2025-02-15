////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "DelegateProperty.hpp"
#include <yt/api/Delegate.hpp>
#include <yt/api/Tachyon.hpp>
#include <yt/api/meta/DelegateGetter.hpp>
#include <yt/api/meta/DelegateSetter.hpp>
#include <yt/logging.hpp>
#include <yt/errors.hpp>

namespace yq::tachyon {
    DelegateProperty::DelegateProperty(std::string_view zName, const std::source_location& sl, const DelegateInfo& theDelegate, ObjectInfo* parent) :
        Meta(zName, parent, sl), m_delegate(theDelegate)
    {
        assert(parent);
        
        if(TachyonInfo* ti = dynamic_cast<TachyonInfo*>(parent)){
            if(ti->m_delegates.local.keys.has(zName))
                tachyonCritical << "DelegateProperty::DelegateProperty(" << parent->name() << "." << zName << ") -- duplicate detected!";
            ti->m_delegates.local << this;
        }
    }

    DelegateCPtr           DelegateProperty::get(const Object*tac) const
    {
        if(!tac)
            return {};
        if(!m_getter)
            return {};
        return m_getter -> get(tac);
    }
    
    std::error_code     DelegateProperty::set(Object*tac, const DelegateCPtr& ap) const
    {
        if(!tac)
            return errors::null_pointer();
        if(!m_setter)
            return errors::no_setter();
        return m_setter->set(tac, ap);
    }
}
