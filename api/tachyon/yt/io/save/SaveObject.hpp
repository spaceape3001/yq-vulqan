////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/typedef/save.hpp>
#include <yq/core/Any.hpp>
#include <yq/core/Ref.hpp>
#include <yt/keywords.hpp>

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
    
    enum class SaveType {
        Object,
        Asset,
        Delegate,
        Tachyon,
        Thread
    };

    class SaveObject  {
    public:
        SaveObject(Save&, const Object&, uint64_t);
        SaveObject(Save&, const ObjectInfo*, uint64_t);
        
        uint64_t            id() const { return m_id; };
        const ObjectInfo*   info() const { return m_info; }
        
        uint64_t            remap() const { return m_remapId; }
        
        virtual bool        valid() const;
        
        virtual bool        isAsset() const { return false; }
        virtual bool        isDelegate() const { return false; }
        virtual bool        isTachyon() const { return false; }
        virtual bool        isThread() const { return false; }
        virtual SaveType    saveType() const { return SaveType::Object; }
        
        size_t      count(property_k) const;
        
        using PropertyVector    = std::vector<SaveProperty>;
        
        const PropertyVector&   properties() const { return m_properties; }
        
    protected:
        virtual ~SaveObject();
        friend class Save;

    private:
        friend class Save;
        
        Save&               m_save;
        const ObjectInfo*   m_info              = nullptr;
        uint64_t            m_id                = 0;
        uint64_t            m_remapId           = 0;
        PropertyVector      m_properties;

        SaveObject(const SaveObject&) = delete;
        SaveObject(SaveObject&&) = delete;
        SaveObject& operator=(const SaveObject&) = delete;
        SaveObject& operator=(SaveObject&&) = delete;
    };
}
