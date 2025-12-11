////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/net/Url.hpp>
#include <yq/tachyon/typedef/raster.hpp>
#include <yq/typedef/filesystem_path.hpp>
#include <system_error>
#include <iosfwd>

//  HMV is a simple data format, modelled after CSV except we've got multiple components
//  So it's comma & semi-colon separated....

namespace yq::tachyon {
    RasterPtr       loadHMV(const std::filesystem::path&);
    RasterPtr       loadHMV(std::istream&, const Url& url={});
    std::error_code saveHMV(const Raster&, const std::filesystem::path&);
    std::error_code saveHMV(const Raster&, std::ostream&, const Url& url={});
}

