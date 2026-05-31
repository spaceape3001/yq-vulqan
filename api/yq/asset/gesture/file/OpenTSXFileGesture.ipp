////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "OpenTSXFileGesture.hpp"
#include <yq/tachyon/api/GestureMetaWriter.hpp>
#include <yq/tachyon/command/file/OpenTSXFileCommand.hpp>
#include <yq/tachyon/io/Save.hpp>
#include <yq/tachyon/io/ResourceFilters.hxx>

YQ_OBJECT_IMPLEMENT(yq::tachyon::OpenTSXFileGesture)

namespace yq::tachyon {
    OpenTSXFileGesture::OpenTSXFileGesture(TypedID tgt, const std::string& path) : 
        OpenFileGesture("OpenTSXFile", {
            .filters = resource_load_filters<Save>(),
            .path    = path,
            .title   = "Pick TSX to load"
        }), m_target(tgt)
    {
    }
    
    OpenTSXFileGesture::~OpenTSXFileGesture()
    {
    }
    
    void OpenTSXFileGesture::open(const std::string& s) 
    {
        send(new OpenTSXFileCommand({.target=m_target}, s));
    }
}

