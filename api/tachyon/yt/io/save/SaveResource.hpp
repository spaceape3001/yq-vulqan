////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/io/save/SaveAsset.hpp>
#include <filesystem>

namespace yq::tachyon {
    class Save;
    class AssetProperty;
    class Resource;
    class ResourceInfo;
    
    class SaveResource : public SaveAsset {
    public:
        SaveResource(Save&, const Resource&);
        SaveResource(Save&, std::string_view, uint64_t, const std::filesystem::path&);
        
        const ResourceInfo* info() const;
        virtual bool        isResource() const override { return true; }
        virtual bool        valid() const override;

    protected:
        virtual ~SaveResource();

    private:
        struct asset_t {
            const AssetProperty*    info    = nullptr;
            uint64_t                asset   = 0;
        };
        std::vector<asset_t>        m_assets;
    };
}
