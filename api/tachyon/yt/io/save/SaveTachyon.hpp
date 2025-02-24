////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/io/save/SaveObject.hpp>
#include <yt/api/StdThread.hpp>

namespace yq::tachyon {
    class Tachyon;
    class TachyonInfo;
    class Save;
    class AssetProperty;
    class DelegateProperty;
    class SaveAsset;
    class SaveDelegate;
    
    class SaveTachyon : public SaveObject {
    public:
        SaveTachyon(Save&, const Tachyon&);
        SaveTachyon(Save&, const TachyonInfo*, uint64_t);
        
        const TachyonInfo*  info() const;
        virtual bool        valid() const override;
        virtual bool        isTachyon() const { return true; }
        virtual SaveType    saveType() const override { return SaveType::Tachyon; }

        struct asset_t {
            const AssetProperty*    info        = nullptr;
            SaveAsset*              asset       = nullptr;
        };
        
        struct delegate_t {
            const DelegateProperty* info        = nullptr;
            SaveDelegate*           delegate    = nullptr;
        };

        const std::vector<asset_t>&     assets() const { return m_assets; }
        const std::vector<delegate_t>&  delegates() const { return m_delegates; }

        using owner_spec_t = std::variant<std::monostate, uint64_t, StdThread>;
        
        uint64_t                parent() const { return m_parent; }
        const owner_spec_t&     owner() const { return m_owner; }
        const std::vector<uint64_t>&    children() const { return m_children; }
        
        using SaveObject::append;
        
        void        append(asset_t);
        void        append(delegate_t);
        
        void        append(child_k, uint64_t);
        
        void    set_parent(uint64_t);
        void    set_owner(owner_spec_t);
    
    protected:
        virtual ~SaveTachyon();
        
    private:
        
        
        uint64_t                    m_parent = 0;
        owner_spec_t                m_owner;
        std::vector<asset_t>        m_assets;
        std::vector<delegate_t>     m_delegates;
        std::vector<uint64_t>       m_children;
    };
}
