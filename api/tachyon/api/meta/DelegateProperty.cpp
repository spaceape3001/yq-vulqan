////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "DelegateProperty.hpp"
#include <tachyon/api/Delegate.hpp>
#include <tachyon/api/Tachyon.hpp>
#include <tachyon/api/meta/DelegateGetter.hpp>
#include <tachyon/api/meta/DelegateSetter.hpp>
#include <tachyon/logging.hpp>
#include <tachyon/errors.hpp>

namespace yq::tachyon {
    DelegateProperty::DelegateProperty(std::string_view zName, const std::source_location& sl, const DelegateInfo& theDelegate, ObjectInfo* parent) :
        Meta(zName, parent, sl), m_delegate(theDelegate)
    {
        assert(parent);
        
        if(TachyonMeta* ti = dynamic_cast<TachyonMeta*>(parent)){
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
