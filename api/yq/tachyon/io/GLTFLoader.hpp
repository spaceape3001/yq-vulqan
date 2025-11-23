////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

//#include <iosfwd>
//#include <yq/typedef/resource.hpp>
#include <yq/typedef/filesystem_path.hpp>
#include <yq/tachyon/pipeline/DataFormat.hpp>
#include <yq/tachyon/typedef/asset_pack.hpp>
#include <yq/tachyon/typedef/gltf.hpp>
#include <yq/tachyon/typedef/raster.hpp>
#include <yq/tachyon/typedef/sampler.hpp>

namespace tinygltf {
    struct Image;
    struct Sampler;
}

namespace yq::tachyon {
    AssetPackCPtr           loadGLTF(const std::filesystem::path&);
    
    DataFormat              data_format(const tinygltf::Image&);
    RasterPtr               to_raster(const tinygltf::Image&);
    SamplerPtr              to_sampler(const tinygltf::Sampler&);
    tinygltf::ModelSPtr     raw_load_gltf(const std::filesystem::path& fp);
}
