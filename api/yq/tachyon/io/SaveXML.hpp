////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/typedef/save.hpp>
#include <yq/typedef/filesystem_path.hpp>
#include <yq/typedef/url.hpp>
#include <yq/typedef/xml.hpp>

namespace yq::tachyon {
    save_ptr_x      loadTSX(const std::filesystem::path&);
    save_ptr_x      loadTSX(const XmlDocument&, const Url&);
    std::error_code saveTSX(const Save&, const std::filesystem::path&);
    std::error_code saveTSX(const Save&, XmlDocument&);
}
