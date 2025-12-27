////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PickMaterialFileGesture.hpp"
#include <yq/tachyon/api/GestureMetaWriter.hpp>
#include <yq/tachyon/asset/Material.hpp>
#include <yq/tachyon/asset/Raster.hpp>
#include <yq/tachyon/asset/Texture.hpp>
#include <yq/tachyon/command/material/SetMaterialSpecCommand.hpp>
#include <yq/tachyon/io/ResourceFilters.hxx>

YQ_OBJECT_IMPLEMENT(yq::tachyon::PickMaterialFileGesture)

namespace yq::tachyon {
    PickMaterialFileGesture::PickMaterialFileGesture(TypedID tgt, const std::string& path) : 
        OpenFileGesture("PickMaterialFile", {
            .filters = resource_load_filters<Material>(),
            .path    = path,
            .title   = "Pick Material/Texture/Image File"
        }), m_target(tgt)
    {
    }
    
    PickMaterialFileGesture::~PickMaterialFileGesture()
    {
    }
    
    void PickMaterialFileGesture::open(const std::string& s) 
    {
        send(new SetMaterialSpecCommand({.target=m_target}, s));
    }
}

