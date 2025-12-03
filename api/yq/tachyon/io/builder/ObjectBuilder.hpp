////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/io/Builder.hpp>
#include <yq/typedef/string_maps.hpp>

namespace yq { 
    class Object; 
    class ObjectMeta;
}

namespace yq::tachyon {
    struct ObjectSave {
        std::string         type;
        string_any_xmap_t   properties;
    };

    class ObjectBuilder : public Builder {
    public:
        ObjectBuilder(const Object&);
        ObjectBuilder(const ObjectSave&);
        virtual ~ObjectBuilder();
        
        virtual bool is_object() const override { return true; }
        
        // if NULL, means the name is unrecognized
        const ObjectMeta*   meta() const { return m_meta; }
        const std::string&  meta_name() const { return m_metaName; }
        
    private:
        const ObjectMeta*   m_meta = nullptr;
        std::string         m_metaName;
        string_any_xmap_t   m_properties;
    };
}
