////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PickHeightFieldFileGesture.hpp"
#include <yq/tachyon/api/GestureMetaWriter.hpp>
#include <yq/tachyon/asset/HeightField.hpp>
#include <yq/tachyon/command/height_field/SetHeightFieldSpecCommand.hpp>
#include <yq/tachyon/io/ResourceFilters.hxx>

YQ_OBJECT_IMPLEMENT(yq::tachyon::PickHeightFieldFileGesture)

namespace yq::tachyon {
    PickHeightFieldFileGesture::PickHeightFieldFileGesture(TypedID tgt, const std::string& path) : 
        OpenFileGesture("PickHeightFieldFile", {
            .filters = resource_load_filters<HeightField>(),
            .path    = path,
            .title   = "Pick Height Field File"
        }), m_target(tgt)
    {
    }
    
    PickHeightFieldFileGesture::~PickHeightFieldFileGesture()
    {
    }
    
    void PickHeightFieldFileGesture::open(const std::string& s) 
    {
        send(new SetHeightFieldSpecCommand({.target=m_target}, s));
    }
}

