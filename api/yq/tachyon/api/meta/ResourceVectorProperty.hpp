////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/meta/Meta.hpp>
#include <yq/meta/MetaBinder.hpp>
#include <yq/resource/Resource.hpp>
#include <yq/typedef/expected.hpp>

namespace yq {
    class Object;
    class ObjectMeta;
}


namespace yq::tachyon {

    class ResourceVectorAppend;
    class ResourceVectorCount;
    class ResourceVectorClear;
    class ResourceVectorEmpty;

    class ResourceVectorEAdd;
    class ResourceVectorErase;
    class ResourceVectorEGet;
    class ResourceVectorESet;
    class ResourceVectorInsert;
    
    class ResourceVectorGetter;
    class ResourceVectorSetter;
    
    class ResourceVectorProperty : public Meta {
        friend class ResourceVectorAppend;
        friend class ResourceVectorClear;
        friend class ResourceVectorCount;
        friend class ResourceVectorEAdd;
        friend class ResourceVectorErase;
        friend class ResourceVectorEGet;
        friend class ResourceVectorEmpty;
        friend class ResourceVectorESet;
        friend class ResourceVectorGetter;
        friend class ResourceVectorInsert;
        friend class ResourceVectorSetter;
    public:

        //! Our writer
        template <SomeResource> class Writer;
        
        //! Writer for statics
        //template <SomeResource> class VarW;
        
        //! Writer for dynamics
        template <SomeObject, SomeResource> class PropW;


        //! Appends the resource (if valid) to the end of the object's corresponding resource vector
        std::error_code     add(Object*, const ResourceCPtr&) const;
        

        //! Appends the resources (if valid) to the end of the object's corresponding resource vector
        std::error_code     append(Object*, ResourceCPtrCSpan) const;
        

        //! Clears the object's corresponding resource vector
        std::error_code     clear(Object*) const;
        
        //! Returns the count of resources in the object's corresponding resource vector
        size_x              count(const Object*) const;
        
        //! Returns TRUE if the object's corresponding resource vector is empty
        boolean_x           empty(const Object*) const;
        
        //! Erases the specified item from the object's corresponding resource vector [0...N-1]
        std::error_code     erase(Object*, size_t) const;
        
        //! Inserts this item *BEFORE* the specified index in the object's correspoinding resource vector
        //! \note May FAIL if the specified item does not exist
        std::error_code     insert(Object*, size_t, const ResourceCPtr&) const;
        
        //! Gets the entire resource vector from the object
        ResourceCPtrVector  get(const Object*) const;
        
        //! Gets a specific item from the object's resource vector
        ResourceCPtr        get(const Object*, size_t) const;
        
        
        //! Sets the entire resource vector on the given object
        std::error_code     set(Object*, ResourceCPtrCSpan) const;
        
        //! Sets the specific item on the object's resource vector
        //! \note May FAIL if the specified item does not exist
        std::error_code     set(Object*, size_t, const ResourceCPtr&) const;

        
        const ResourceVectorEAdd* adder() const { return m_eadd; }
        const ResourceVectorAppend* appender() const { return m_append; }
        const ResourceVectorClear* clearer() const { return m_clear; }
        const ResourceVectorCount* counter() const { return m_count; }
        const ResourceVectorEmpty* emptier() const { return m_empty; }
        const ResourceVectorErase* eraser() const { return m_erase; }
        const ResourceVectorEGet*   getter() const { return m_eget; }
        const ResourceVectorGetter* getter(all_k) const { return m_getter; }
        const ResourceVectorInsert* inserter() const { return m_insert; }
        const ResourceVectorESet* setter() const { return m_eset; }
        const ResourceVectorSetter* setter(all_k) const { return m_setter; }
        
        const ResourceMeta&         resource() const { return m_resource; }


        /*! \brief Master Constructor 
            \note   Only use directly this if you know what you're doing, otherwise, stay away
            \param[in] zName    name of the property
            \param[in] sl       Source location of the definition (usually auto-picked up by the meta declare helpers
            \param[in] type     Data type for the property
            \param[in] parent   Parent object this is apart of
            \param[in] opts     Options
        */
        ResourceVectorProperty(std::string_view zName, const std::source_location& sl, const ResourceMeta& type, ObjectMeta* parent);
    
    private:
        const ResourceMeta&             m_resource;

        const ResourceVectorAppend*     m_append    = nullptr;
        const ResourceVectorClear*      m_clear     = nullptr;
        const ResourceVectorCount*      m_count     = nullptr;
        const ResourceVectorEAdd*       m_eadd      = nullptr;
        const ResourceVectorEGet*       m_eget      = nullptr;
        const ResourceVectorEmpty*      m_empty     = nullptr;
        const ResourceVectorErase*      m_erase     = nullptr;
        const ResourceVectorESet*       m_eset      = nullptr;
        const ResourceVectorGetter*     m_getter    = nullptr;
        const ResourceVectorInsert*     m_insert    = nullptr;
        const ResourceVectorSetter*     m_setter    = nullptr;
    };
}

