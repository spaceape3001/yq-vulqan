////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "VulqanConfig.hpp"
#include <yq/process/Settings.hpp>
#include <yq/text/vsplit.hpp>
#include <yq/text/transform.hpp>

namespace yq::tachyon {
    VulqanConfig::VulqanConfig(const std::filesystem::path& pth)
    {
        m_settings    = std::make_shared<Settings>(pth);
    }
    
    VulqanConfig::~VulqanConfig() = default;
    
    VulqanConfig::VulqanConfig(const VulqanConfig&) = default;
    VulqanConfig::VulqanConfig(VulqanConfig&&) = default;
    VulqanConfig& VulqanConfig::operator=(const VulqanConfig&) = default;
    VulqanConfig& VulqanConfig::operator=(VulqanConfig&&) = default;
    
    string_view_vector_t    VulqanConfig::data_paths() const
    {
        string_view_vector_t   ret;
        vsplit(m_settings->value("data"), ';', [&](std::string_view v){
            ret.push_back(trimmed(v));
        });
        return ret;
    }

    string_view_vector_t    VulqanConfig::vulqan_libraries() const
    {
        string_view_vector_t   ret;
        vsplit(m_settings->value("libraries"), ';', [&](std::string_view v){
            ret.push_back(trimmed(v));
        });
        return ret;
    }
}

