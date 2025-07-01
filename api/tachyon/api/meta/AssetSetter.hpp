////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/meta/Meta.hpp>
#include <yq/typedef/asset.hpp>

namespace yq {
    class Asset;
    class Object;
    class ObjectInfo;
}

namespace yq::tachyon {
    class AssetProperty;

    /*! \brief Abstract PropGetter
        
        This is an abstract "setter" that may or may not have an object associated with it.
    */
    class AssetSetter : public Meta {
    public:
    
        /*! \brief "Sets" a property
        
            \param[out] obj     Pointer to object to set, can be null on a static object
            \param[in] value    Pointer to value to use on set, assumed to match data()
        */
        virtual std::error_code set(Object*obj, const AssetCPtr&) const = 0;
        
        //! Data type for the setter
        virtual const AssetMeta&        asset() const = 0;
        
        //! Object type for the setter
        virtual const ObjectInfo&       object() const = 0;
        
        //! Property info this belongs to
        const AssetProperty*            property() const;
        
    protected:
    
        /*! \brief Constructor
        
            \param[in] delInfo  Property to attach this setter to
            \param[in] sl       Source location it's defined
        */
        AssetSetter(AssetProperty* assetProp, const std::source_location& sl);
    };
}
