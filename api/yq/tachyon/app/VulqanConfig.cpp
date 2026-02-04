////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "VulqanConfig.hpp"
#include <yq/config/config.hpp>
//#include <yq/process/Settings.hpp>
#include <yq/text/vsplit.hpp>
#include <yq/text/transform.hpp>

namespace yq::tachyon {
    VulqanConfig::VulqanConfig()
    {
    }
    
    VulqanConfig::~VulqanConfig() = default;
    
    VulqanConfig::VulqanConfig(const VulqanConfig&) = default;
    VulqanConfig::VulqanConfig(VulqanConfig&&) = default;
    VulqanConfig& VulqanConfig::operator=(const VulqanConfig&) = default;
    VulqanConfig& VulqanConfig::operator=(VulqanConfig&&) = default;
    
    string_view_vector_t    VulqanConfig::data_paths() const
    {
        string_view_vector_t   ret;
        vsplit(config::data_dir(), ';', [&](std::string_view v){
            ret.push_back(trimmed(v));
        });
        return ret;
    }

    string_view_vector_t    VulqanConfig::vulqan_libraries() const
    {
        string_view_vector_t   ret;
        vsplit(config::vklibs(), ';', [&](std::string_view v){
            ret.push_back(trimmed(v));
        });
        return ret;
    }
}

