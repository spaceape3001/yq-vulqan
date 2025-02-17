////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/io/save/SaveObject.hpp>

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

        const std::vector<asset_t>& assets() const { return m_assets; }
        const std::vector<delegate_t>& delegates() const { return m_delegates; }
    
    protected:
        virtual ~SaveTachyon();
        
    private:
        
        std::vector<asset_t>        m_assets;
        std::vector<delegate_t>     m_delegates;
    };
}
