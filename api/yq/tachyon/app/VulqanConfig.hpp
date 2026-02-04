////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <yq/typedef/string_vectors.hpp>
#include <filesystem>
#include <memory>

namespace yq {
    class Settings;
}

namespace yq::tachyon {
    class VulqanConfig {
    public:
        VulqanConfig();
        ~VulqanConfig();
        
        VulqanConfig(const VulqanConfig&);
        VulqanConfig(VulqanConfig&&);
        VulqanConfig& operator=(const VulqanConfig&);
        VulqanConfig& operator=(VulqanConfig&&);
        
        string_view_vector_t    vulqan_libraries() const;
        string_view_vector_t    data_paths() const;

    private:
        //std::shared_ptr<Settings>   m_settings;
    };
}

