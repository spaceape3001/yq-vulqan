////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SaveTSXFileGesture.hpp"
#include <yq/tachyon/api/GestureMetaWriter.hpp>
#include <yq/tachyon/command/file/SaveAsTSXFileCommand.hpp>
#include <yq/tachyon/io/Save.hpp>
#include <yq/tachyon/io/ResourceFilters.hxx>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SaveTSXFileGesture)

namespace yq::tachyon {
    SaveTSXFileGesture::SaveTSXFileGesture(TypedID tgt, const std::string& path) : 
        SaveFileGesture("SaveTSXFile", {
            .filters = resource_save_filters<Save>(),
            .path    = path,
            .title   = "Pick TSX to save"
        }), m_target(tgt)
    {
    }
    
    SaveTSXFileGesture::~SaveTSXFileGesture()
    {
    }
    
    void SaveTSXFileGesture::save(const std::string& s) 
    {
        send(new SaveAsTSXFileCommand({.target=m_target}, s));
    }
}

