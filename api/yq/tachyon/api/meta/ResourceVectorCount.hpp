////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/meta/Meta.hpp>
#include <yq/typedef/expected.hpp>
#include <yq/typedef/resource.hpp>

namespace yq {
    class ResourceMeta;
    class Object;
    class ObjectMeta;
}

namespace yq::tachyon {
    class ResourceVectorProperty;

    /*! \brief Abstract PropGetter
        
        This is an abstract "appender" that may or may not have an object associated with it.
    */
    class ResourceVectorCount : public Meta {
    public:
    
        virtual size_x      count(const Object* obj) const = 0;

        /*! \brief Object/Type meta type expected for src
        
            \note This will be invalid() for static properties.
        */
        virtual const ObjectMeta&       object() const = 0;
        
        /*! \brief Object/Type for the data
        */
        virtual const ResourceMeta&     resource() const = 0;
        
        /*! \brief Property this is associated with.
        */
        const ResourceVectorProperty* property() const;

    protected:
        ResourceVectorCount(ResourceVectorProperty*, const std::source_location& sl);
    };
    
}

