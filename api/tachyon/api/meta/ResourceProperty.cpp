////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ResourceProperty.hpp"
#include <yq/resource/Resource.hpp>
#include <tachyon/api/Tachyon.hpp>
#include <tachyon/api/meta/ResourceGetter.hpp>
#include <tachyon/api/meta/ResourceSetter.hpp>
#include <tachyon/logging.hpp>
#include <tachyon/errors.hpp>

namespace yq::tachyon {
    ResourceProperty::ResourceProperty(std::string_view zName, const std::source_location& sl, const ResourceMeta& theResource, ObjectMeta* parent) :
        Meta(zName, parent, sl), m_resource(theResource)
    {
        assert(parent);
        
        if(TachyonMeta* ti = dynamic_cast<TachyonMeta*>(parent)){
            if(ti->m_resources.local.keys.has(zName))
                tachyonCritical << "ResourceProperty::ResourceProperty(" << parent->name() << "." << zName << ") -- duplicate detected!";
            ti->m_resources.local << this;
        }
    }

    ResourceCPtr           ResourceProperty::get(const Object*tac) const
    {
        if(!m_getter)
            return {};
        return m_getter -> get(tac);
    }
    
    std::error_code     ResourceProperty::set(Object*tac, const ResourceCPtr& ap) const
    {
        if(!m_setter)
            return errors::no_setter();
        return m_setter->set(tac, ap);
    }
}
