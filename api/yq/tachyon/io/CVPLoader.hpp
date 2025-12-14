////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/net/Url.hpp>
#include <yq/tachyon/typedef/texture.hpp>
#include <yq/typedef/filesystem_path.hpp>
#include <system_error>
#include <iosfwd>

namespace yq::tachyon {
    TexturePtr       loadCVP(const std::filesystem::path&);
    TexturePtr       loadCVP(std::istream&, const Url& url={});
}
