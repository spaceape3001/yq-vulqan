////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/typedef/save.hpp>
#include <yq/core/Any.hpp>
#include <yq/core/Ref.hpp>

namespace yq { 
    class Object; 
    class ObjectInfo; 
    class PropertyInfo;
}


namespace yq::tachyon {
    class Save;

    struct SaveProperty {
        const PropertyInfo*         info    = nullptr;
        Any                         value;
    };

    class SaveObject  {
    public:
        SaveObject(Save&, const Object&, uint64_t);
        SaveObject(Save&, std::string_view, uint64_t);
        
        uint64_t            id() const { return m_id; };
        const ObjectInfo*   info() const { return m_info; }
        
        virtual bool        valid() const;
        
        virtual bool        isAsset() const { return false; }
        virtual bool        isDelegate() const { return false; }
        virtual bool        isResource() const { return false; }
        virtual bool        isTachyon() const { return false; }
        virtual bool        isThread() const { return false; }
        
    protected:
        virtual ~SaveObject();
        friend class Save;

    private:
        Save&                       m_save;
        const ObjectInfo*           m_info              = nullptr;
        uint64_t                    m_id                = 0;
        std::vector<SaveProperty>   m_properties;

        SaveObject(const SaveObject&) = delete;
        SaveObject(SaveObject&&) = delete;
        SaveObject& operator=(const SaveObject&) = delete;
        SaveObject& operator=(SaveObject&&) = delete;
    };
}
