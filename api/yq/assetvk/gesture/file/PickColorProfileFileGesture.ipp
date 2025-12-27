////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PickColorProfileFileGesture.hpp"
#include <yq/tachyon/api/GestureMetaWriter.hpp>
#include <yq/tachyon/asset/ColorProfile.hpp>
#include <yq/tachyon/command/color_profile/SetColorProfileSpecCommand.hpp>
#include <yq/tachyon/io/ResourceFilters.hxx>

YQ_OBJECT_IMPLEMENT(yq::tachyon::PickColorProfileFileGesture)

namespace yq::tachyon {
    PickColorProfileFileGesture::PickColorProfileFileGesture(TypedID tgt, const std::string& path) : 
        OpenFileGesture("PickColorProfileFile", {
            .filters = resource_load_filters<ColorProfile>(),
            .path    = path,
            .title   = "Pick Color Profile File"
        }), m_target(tgt)
    {
    }
    
    PickColorProfileFileGesture::~PickColorProfileFileGesture()
    {
    }
    
    void PickColorProfileFileGesture::open(const std::string& s) 
    {
        send(new SetColorProfileSpecCommand({.target=m_target}, s));
    }
}

