////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/meta/Meta.hpp>
#include <yq/meta/InfoBinder.hpp>
#include <yq/typedef/asset.hpp>

namespace yq {
    class Object;
    class ObjectInfo;
}


namespace yq::tachyon {
    class AssetGetter;
    class AssetSetter;
    
    /*! \brief Asset property (of tachyon, other assets)
    */
    class AssetProperty : public Meta {
        friend class AssetGetter;
        friend class AssetSetter;
    public:
    
        using Meta::set;
    
        //! Our writer
        template <typename T> class Writer;
        
        //! Writer for statics
        template <typename T> class VarW;
        
        //! Writer for dynamics
        template <typename C, typename T> class PropW;

        const AssetInfo&    asset() const { return m_asset; }
        
        AssetCPtr           get(const Object*) const;
        std::error_code     set(Object*, const AssetCPtr&) const;
        
        //! Our getter
        const AssetGetter*   getter() const { return m_getter; }

        //! Our setter (may be NULL for read-only)
        const AssetSetter*   setter() const { return m_setter; }

        /*! \brief Master Constructor 
            \note   Only use directly this if you know what you're doing, otherwise, stay away
            \param[in] zName    name of the property
            \param[in] sl       Source location of the definition (usually auto-picked up by the meta declare helpers
            \param[in] type     Data type for the property
            \param[in] parent   Parent object this is apart of
            \param[in] opts     Options
        */
        AssetProperty(std::string_view zName, const std::source_location& sl, const AssetInfo& type, ObjectInfo* parent);

    private:
        const AssetSetter*      m_setter    = nullptr;
        const AssetGetter*      m_getter    = nullptr;
        const AssetInfo&        m_asset;
    };
}
