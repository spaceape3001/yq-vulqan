////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

//#include <iosfwd>
//#include <yq/typedef/resource.hpp>
#include <yq/typedef/filesystem_path.hpp>
#include <yq/tachyon/typedef/asset_pack.hpp>
//#include <yq/tachyon/typedef/raster.hpp>
//#include <yq/tachyon/typedef/sampler.hpp>

//namespace tinygltf {
    //struct Image;
    //struct Sampler;
//}

namespace yq::tachyon {
    AssetPackCPtr        loadGLTF(const std::filesystem::path&);
    
    //RasterPtr               to_raster(const tinygltf::Image&);
    //SamplerPtr              to_sampler(const tinygltf::Sampler&);
}
