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
    class SaveAsset : public SaveObject {
    public:
        SaveAsset(const Asset&);
        SaveAsset(std::string_view, uint64_t, const std::filesystem::path&);
        
        const AssetInfo* info() const;
        virtual bool    valid() const override;
        
        const std::filesystem::path&    filepath() const { return m_filepath; }
        
    protected:
        virtual ~SaveAsset();
    private:
        std::filesystem::path       m_filepath;
    };
}
