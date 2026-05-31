////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PickRasterFileGesture.hpp"
#include <yq/tachyon/api/GestureMetaWriter.hpp>
#include <yq/tachyon/asset/Raster.hpp>
#include <yq/tachyon/command/raster/SetRasterSpecCommand.hpp>
#include <yq/tachyon/io/ResourceFilters.hxx>

YQ_OBJECT_IMPLEMENT(yq::tachyon::PickRasterFileGesture)

namespace yq::tachyon {
    PickRasterFileGesture::PickRasterFileGesture(TypedID tgt, const std::string& path) : 
        OpenFileGesture("PickRasterFile", {
            .filters = resource_load_filters<Raster>(),
            .path    = path,
            .title   = "Pick Image"
        }), m_target(tgt)
    {
    }
    
    PickRasterFileGesture::~PickRasterFileGesture()
    {
    }
    
    void PickRasterFileGesture::open(const std::string& s) 
    {
        send(new SetRasterSpecCommand({.target=m_target}, s));
    }
}

