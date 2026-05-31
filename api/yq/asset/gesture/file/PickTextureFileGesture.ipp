////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PickTextureFileGesture.hpp"
#include <yq/tachyon/api/GestureMetaWriter.hpp>
#include <yq/tachyon/asset/Raster.hpp>
#include <yq/tachyon/asset/Texture.hpp>
#include <yq/tachyon/command/texture/SetTextureSpecCommand.hpp>
#include <yq/tachyon/io/ResourceFilters.hxx>

YQ_OBJECT_IMPLEMENT(yq::tachyon::PickTextureFileGesture)

namespace yq::tachyon {
    PickTextureFileGesture::PickTextureFileGesture(TypedID tgt, const std::string& path) : 
        OpenFileGesture("PickTextureFile", {
            .filters = resource_load_filters<Texture, Raster>(),
            .path    = path,
            .title   = "Pick Texture File"
        }), m_target(tgt)
    {
    }
    
    PickTextureFileGesture::~PickTextureFileGesture()
    {
    }
    
    void PickTextureFileGesture::open(const std::string& s) 
    {
        send(new SetTextureSpecCommand({.target=m_target}, s));
    }
}

