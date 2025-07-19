////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/io/save/SaveObject.hpp>
#include <tachyon/api/StdThread.hpp>
#include <tachyon/typedef/tachyon.hpp>

namespace yq::tachyon {
    class Tachyon;
    class TachyonMeta;
    class Save;
    class ResourceProperty;
    class DelegateProperty;
    class SaveResource;
    class SaveDelegate;
    
    class SaveTachyon : public SaveObject {
    public:
        SaveTachyon(Save&, const Tachyon&);
        SaveTachyon(Save&, const TachyonMeta*, uint64_t);
        
        const TachyonMeta*  info() const;
        virtual bool        valid() const override;
        virtual bool        isTachyon() const { return true; }
        virtual SaveType    saveType() const override { return SaveType::Tachyon; }

        struct resource_t {
            const ResourceProperty*    info        = nullptr;
            SaveResource*              resource       = nullptr;
        };
        
        struct delegate_t {
            const DelegateProperty* info        = nullptr;
            SaveDelegate*           delegate    = nullptr;
        };

        const std::vector<resource_t>&     resources() const { return m_resources; }
        const std::vector<delegate_t>&  delegates() const { return m_delegates; }

        using owner_spec_t = std::variant<std::monostate, uint64_t, StdThread>;
        
        uint64_t                parent() const { return m_parent; }
        const owner_spec_t&     owner() const { return m_owner; }
        const std::vector<uint64_t>&    children() const { return m_children; }
        
        using SaveObject::append;
        
        void        append(resource_t);
        void        append(delegate_t);
        
        void        append(child_k, uint64_t);
        
        void    set_parent(uint64_t);
        void    set_owner(owner_spec_t);
    
        const AttrIDMap&            prog_attributes() const { return m_progAttrs; }
        const AttrKeyMap&           user_attributes() const { return m_userAttrs; }
        
        Any&                        create_attribute(int);
        Any&                        create_attribute(const std::string&);
    
    protected:
        virtual ~SaveTachyon();
        
    private:
        
        
        uint64_t                    m_parent = 0;
        owner_spec_t                m_owner;
        std::vector<resource_t>        m_resources;
        std::vector<delegate_t>     m_delegates;
        std::vector<uint64_t>       m_children;
        AttrIDMap                   m_progAttrs;
        AttrKeyMap                  m_userAttrs;
    };
}
