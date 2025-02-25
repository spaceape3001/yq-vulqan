////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/meta/Meta.hpp>
#include <yq/typedef/asset.hpp>

namespace yq {
    class AssetInfo;
    class Object;
    class ObjectInfo;
}

namespace yq::tachyon {
    class AssetProperty;

    /*! \brief Abstract PropGetter
        
        This is an abstract "getter" that may or may not have an object associated with it.
    */
    class AssetGetter : public Meta {
    public:
    
        /*! \brief "Gets" the value for the meta
        
            \param[out] dst     Pointer to destination, assumed to be correct buffer.
            \param[in] obj      Pointer to the object, if used.  (Ignored on static properties.)
        */
        virtual AssetCPtr           get(const Object* obj) const = 0;

        /*! \brief Object/Type meta type expected for src
        
            \note This will be invalid() for static properties.
        */
        virtual const ObjectInfo&    object() const = 0;
        
        /*! \brief Object/Type for the data
        */
        virtual const AssetInfo&     asset() const = 0;
        
        /*! \brief Property this is associated with.
        */
        const AssetProperty* property() const;

    protected:
        AssetGetter(AssetProperty*, const std::source_location& sl);
    };
    
}
