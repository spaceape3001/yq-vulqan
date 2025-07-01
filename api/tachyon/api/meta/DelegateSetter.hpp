////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/meta/Meta.hpp>
#include <tachyon/typedef/delegate.hpp>

namespace yq {
    class Object;
    class ObjectMeta;
}

namespace yq::tachyon {
    class Delegate;
    class DelegateProperty;

    /*! \brief Abstract PropGetter
        
        This is an abstract "setter" that may or may not have an object associated with it.
    */
    class DelegateSetter : public Meta {
    public:
    
        /*! \brief "Sets" a property
        
            \param[out] obj     Pointer to object to set, can be null on a static object
            \param[in] value    Pointer to value to use on set, assumed to match data()
        */
        virtual std::error_code         set(Object*obj, const DelegateCPtr&) const = 0;
        
        //! Data type for the setter
        virtual const DelegateMeta&     delegate() const = 0;
        
        //! Object type for the setter
        virtual const ObjectMeta&       object() const = 0;
        
        //! Property info this belongs to
        const DelegateProperty*         property() const;
        
    protected:
    
        /*! \brief Constructor
        
            \param[in] delProp  Property to attach this setter to
            \param[in] sl       Source location it's defined
        */
        DelegateSetter(DelegateProperty* delProp, const std::source_location& sl);
    };
}
