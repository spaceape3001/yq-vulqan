////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/io/save/SaveObject.hpp>
#include <filesystem>

namespace yq {
    class Asset;
    class AssetInfo;
}

namespace yq::tachyon {
    class Save;
    
    class SaveAsset : public SaveObject {
    public:
        SaveAsset(Save&, const Asset&);
        SaveAsset(Save&, std::string_view, uint64_t, const std::filesystem::path&);
        
        const AssetInfo* info() const;
        virtual bool    valid() const override;
        
        const std::filesystem::path&    filepath() const { return m_filepath; }
        
        virtual bool        isAsset() const override { return true; }

    protected:
        virtual ~SaveAsset();
    private:
        std::filesystem::path       m_filepath;
    };
}
