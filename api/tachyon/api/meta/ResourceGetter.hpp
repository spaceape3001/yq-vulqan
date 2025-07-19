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
    class ResourceProperty;

    /*! \brief Abstract PropGetter
        
        This is an abstract "getter" that may or may not have an object associated with it.
    */
    class ResourceGetter : public Meta {
    public:
    
        /*! \brief "Gets" the value for the meta
        
            \param[out] dst     Pointer to destination, assumed to be correct buffer.
            \param[in] obj      Pointer to the object, if used.  (Ignored on static properties.)
        */
        virtual ResourceCPtr           get(const Object* obj) const = 0;

        /*! \brief Object/Type meta type expected for src
        
            \note This will be invalid() for static properties.
        */
        virtual const ObjectMeta&    object() const = 0;
        
        /*! \brief Object/Type for the data
        */
        virtual const ResourceMeta&     resource() const = 0;
        
        /*! \brief Property this is associated with.
        */
        const ResourceProperty* property() const;

    protected:
        ResourceGetter(ResourceProperty*, const std::source_location& sl);
    };
    
}
