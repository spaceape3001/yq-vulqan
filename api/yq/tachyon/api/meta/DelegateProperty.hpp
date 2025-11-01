////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/meta/Meta.hpp>
#include <yq/meta/MetaBinder.hpp>
#include <yq/tachyon/typedef/delegate.hpp>

namespace yq { 
    class Object; 
    class ObjectMeta;
}

namespace yq::tachyon {
    class DelegateGetter;
    class DelegateSetter;
    class DelegateMeta;
    
    class DelegateProperty : public Meta {
        friend class DelegateGetter;
        friend class DelegateSetter;
    public:
    
        using Meta::set;
    
        //! Our writer
        template <typename T> class Writer;
        
        //! Writer for statics
        template <typename T> class VarW;
        
        //! Writer for dynamics
        template <typename C, typename T> class PropW;
        
        const DelegateMeta&     delegate() const { return m_delegate; }
    
        //! Our getter
        const DelegateGetter*   getter() const { return m_getter; }

        //! Our setter (may be NULL for read-only)
        const DelegateSetter*   setter() const { return m_setter; }

        DelegateCPtr            get(const Object*) const;
        std::error_code         set(Object*, const DelegateCPtr&) const;

        /*! \brief Master Constructor 
            \note   Only use directly this if you know what you're doing, otherwise, stay away
            \param[in] zName    name of the property
            \param[in] sl       Source location of the definition (usually auto-picked up by the meta declare helpers
            \param[in] type     Data type for the property
            \param[in] parent   Parent object this is apart of
            \param[in] opts     Options
        */
        DelegateProperty(std::string_view zName, const std::source_location& sl, const DelegateMeta& type, ObjectMeta* parent);

    private:
        const DelegateSetter*   m_setter    = nullptr;
        const DelegateGetter*   m_getter    = nullptr;
        const DelegateMeta&     m_delegate;
    };
}
