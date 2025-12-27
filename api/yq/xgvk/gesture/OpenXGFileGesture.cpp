////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "OpenXGFileGesture.hpp"

#include <yq/tachyon/api/GestureMetaWriter.hpp>
#include <yq/tachyon/io/ResourceFilters.hxx>
#include <yq/xg/XGDocument.hpp>
#include <yq/xgvk/command/OpenXGFileCommand.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::OpenXGFileGesture)

namespace yq::tachyon {
    OpenXGFileGesture::OpenXGFileGesture(TypedID tgt, const std::string& path) : 
        OpenFileGesture("OpenXGFile", {
            .filters = resource_load_filters<XGDocument>(),
            .path    = path,
            .title   = "Pick XG to load"
        }), m_target(tgt)
    {
    }
    
    OpenXGFileGesture::~OpenXGFileGesture()
    {
    }
    
    void OpenXGFileGesture::open(const std::string& s) 
    {
        send(new OpenXGFileCommand({.target=m_target}, s));
    }
}

