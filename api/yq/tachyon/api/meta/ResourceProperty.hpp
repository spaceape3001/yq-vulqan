////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/meta/Meta.hpp>
#include <yq/meta/MetaBinder.hpp>
#include <yq/resource/Resource.hpp>

namespace yq {
    class Object;
    class ObjectMeta;
}


namespace yq::tachyon {
    class ResourceGetter;
    class ResourceSetter;
    
    /*! \brief Resource property (of tachyon, other resources)
    */
    class ResourceProperty : public Meta {
        friend class ResourceGetter;
        friend class ResourceSetter;
    public:
    
        using Meta::set;
    
        //! Our writer
        template <SomeResource> class Writer;
        
        //! Writer for statics
        //template <SomeResource> class VarW;
        
        //! Writer for dynamics
        template <SomeObject, SomeResource> class PropW;

        const ResourceMeta&    resource() const { return m_resource; }
        
        ResourceCPtr           get(const Object*) const;
        std::error_code     set(Object*, const ResourceCPtr&) const;
        
        //! Our getter
        const ResourceGetter*   getter() const { return m_getter; }

        //! Our setter (may be NULL for read-only)
        const ResourceSetter*   setter() const { return m_setter; }

        /*! \brief Master Constructor 
            \note   Only use directly this if you know what you're doing, otherwise, stay away
            \param[in] zName    name of the property
            \param[in] sl       Source location of the definition (usually auto-picked up by the meta declare helpers
            \param[in] type     Data type for the property
            \param[in] parent   Parent object this is apart of
            \param[in] opts     Options
        */
        ResourceProperty(std::string_view zName, const std::source_location& sl, const ResourceMeta& type, ObjectMeta* parent);

    private:
        const ResourceSetter*      m_setter    = nullptr;
        const ResourceGetter*      m_getter    = nullptr;
        const ResourceMeta&        m_resource;
    };
}
