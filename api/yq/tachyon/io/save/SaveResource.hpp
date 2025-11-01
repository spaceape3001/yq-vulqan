////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/io/save/SaveObject.hpp>
#include <filesystem>

namespace yq {
    class Resource;
    class ResourceMeta;
}

namespace yq::tachyon {
    class Save;
    
    class SaveResource : public SaveObject {
    public:
        SaveResource(Save&, const Resource&);
        SaveResource(Save&, const ResourceMeta*, uint64_t, const std::filesystem::path&);
        
        const ResourceMeta*    info() const;
        virtual bool        valid() const override;
        
        const std::filesystem::path&    filepath() const { return m_filepath; }
        
        virtual bool        isResource() const override { return true; }
        virtual SaveType    saveType() const override { return SaveType::Resource; }

    protected:
        virtual ~SaveResource();
    private:
        std::filesystem::path       m_filepath;
    };
}
