////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/typedef/obj.hpp>
#include <filesystem>

namespace yq::tachyon {
    struct ObjLoadOptions {
        std::filesystem::path   mtl_search_path;
        std::string             triangulate     = "simple";
        bool                    vertex_color    = true;
    };

    tinyobj::ObjReaderSPtr     raw_load_obj(const std::filesystem::path& fp, const ObjLoadOptions={});
}

