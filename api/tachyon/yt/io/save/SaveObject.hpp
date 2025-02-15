////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/typedef/save.hpp>
#include <yt/io/save/SaveProperty.hpp>
#include <yq/core/Ref.hpp>

namespace yq { 
    class Object; 
    class ObjectInfo; 
}


namespace yq::tachyon {
    class SaveObject : public RefCount {
    public:
        SaveObject(const Object&, uint64_t);
        SaveObject(std::string_view, uint64_t);
        
        uint64_t            id() const { return m_id; };
        const ObjectInfo*   info() const { return m_info; }
        
        virtual bool        valid() const;
        
    protected:
        virtual ~SaveObject();

    private:
        const ObjectInfo*           m_info              = nullptr;
        uint64_t                    m_id                = 0;
        std::vector<SaveProperty>   m_properties;

        SaveObject(const SaveObject&) = delete;
        SaveObject(SaveObject&&) = delete;
        SaveObject& operator=(const SaveObject&) = delete;
        SaveObject& operator=(SaveObject&&) = delete;
    };
}
