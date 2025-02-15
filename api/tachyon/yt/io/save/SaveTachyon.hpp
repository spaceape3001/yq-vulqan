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
    
    class SaveTachyon : public SaveObject {
    public:
        SaveTachyon(Save&, const Tachyon&);
        SaveTachyon(Save&, std::string_view, uint64_t);
        
        const TachyonInfo*  info() const;
        virtual bool        valid() const override;
        virtual bool        isTachyon() const { return true; }
    
    protected:
        virtual ~SaveTachyon();
        
    private:
        struct asset_t {
            const AssetProperty*    info    = nullptr;
            uint64_t                asset   = 0;
        };
        
        struct delegate_t {
            const DelegateProperty* info    = nullptr;
            uint64_t                asset   = 0;
        };
        
        std::vector<asset_t>        m_assets;
        std::vector<delegate_t>     m_delgates;
    };
}
