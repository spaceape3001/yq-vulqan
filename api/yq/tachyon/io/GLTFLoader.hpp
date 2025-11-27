////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

//#include <iosfwd>
//#include <yq/typedef/resource.hpp>
#include <yq/typedef/expected.hpp>
#include <yq/typedef/filesystem_path.hpp>
#include <yq/tachyon/keywords.hpp>
#include <yq/tachyon/pipeline/DataFormat.hpp>
#include <yq/tachyon/typedef/assetpak.hpp>
#include <yq/tachyon/typedef/gltf.hpp>
#include <yq/tachyon/typedef/mesh.hpp>
#include <yq/tachyon/typedef/raster.hpp>
#include <yq/tachyon/typedef/sampler.hpp>

namespace tinygltf {
    struct Image;
    struct Sampler;
    struct Material;
    struct Mesh;
    struct Model;
}

namespace yq {
    class ByteArray;
}

namespace yq::tachyon {

    /*
        Note, current implementation:
        
        1) Hazy with Mesh Lines, Points
        2) Skips Audio, Cameras, Lights, Materials, Nodes, & Scenes
        3) Meshes won't support Morphing
    */

    DataFormat              data_format(const tinygltf::Image&);
    RasterPtr               to_raster(const tinygltf::Image&);
    SamplerPtr              to_sampler(const tinygltf::Sampler&);
    AssetPakPtr             to_assetpak(const tinygltf::Model&);
    AssetPakPtr             to_assetpak(const tinygltf::Model&, const Url& url);
    
    //! Combined GLTF/GLB loading & parsing (examines the file extension, makes a selection)
    AssetPakCPtr            loadGLTF(const std::filesystem::path&);

    //! Load GLTF/GLB model from file (examines the file extension, makes a selection)
    tinygltf::ModelSPtr     raw_load_gltf(const std::filesystem::path& fp);
    
    //! Loads GLB model from internal buffer
    tinygltf::ModelSPtr     raw_load_gltf(binary_k, const ByteArray&);
    
    //! Loads GLB model from specified file
    tinygltf::ModelSPtr     raw_load_gltf(binary_k, const std::filesystem::path& fp);
    
    //! Loads GLTF model from internal buffer
    tinygltf::ModelSPtr     raw_load_gltf(text_k, const std::string& data, const std::filesystem::path& directory);
    
    //! Loads GLTF model from specified file
    tinygltf::ModelSPtr     raw_load_gltf(text_k, const std::filesystem::path& fp);
}
