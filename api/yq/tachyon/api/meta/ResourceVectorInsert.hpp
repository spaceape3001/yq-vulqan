////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/meta/Meta.hpp>
#include <yq/typedef/resource.hpp>

namespace yq {
    class ResourceMeta;
    class Object;
    class ObjectMeta;
}

namespace yq::tachyon {
    class ResourceVectorProperty;
    
    /*! \brief Abstract Element Insertter (for resources on object)
        
        This is an abstract "getter" that may or may not have an object associated with it.
    */
    class ResourceVectorInsert : public Meta {
    public:
    
        /*! \brief "Inserts" the index for the object's resource vector
        */
        virtual std::error_code         insert(Object* obj, size_t, const ResourceCPtr&) const = 0;

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
        ResourceVectorInsert(ResourceVectorProperty*, const std::source_location& sl);
    };
}
