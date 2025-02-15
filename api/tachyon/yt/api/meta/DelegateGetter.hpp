////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/meta/Meta.hpp>
#include <yt/typedef/delegate.hpp>

namespace yq {
    class Object;
    class ObjectInfo;
}

namespace yq::tachyon {
    class DelegateInfo;
    class DelegateProperty;

    /*! \brief Abstract PropGetter
        
        This is an abstract "getter" that may or may not have an object associated with it.
    */
    class DelegateGetter : public Meta {
    public:
    
        /*! \brief "Gets" the value for the meta
        
            \param[out] dst     Pointer to destination, assumed to be correct buffer.
            \param[in] obj      Pointer to the object, if used.  (Ignored on static properties.)
        */
        virtual const DelegateCPtr       get(const Object* obj) const = 0;

        /*! \brief Object/Type meta type expected for src
        
            \note This will be invalid() for static properties.
        */
        virtual const ObjectInfo&       object() const = 0;
        
        /*! \brief Object/Type for the data
        */
        virtual const DelegateInfo&     delegate() const = 0;
        
        /*! \brief Property this is associated with.
        */
        const DelegateProperty*         property() const;

    protected:
        DelegateGetter(DelegateProperty*, const std::source_location& sl);
    };
    
}
