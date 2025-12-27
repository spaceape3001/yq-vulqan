////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "SaveXGFileGesture.hpp"

#include <yq/tachyon/api/GestureMetaWriter.hpp>
#include <yq/tachyon/io/ResourceFilters.hxx>
#include <yq/xg/XGDocument.hpp>
#include <yq/xgvk/command/SaveXGFileCommand.hpp>

YQ_OBJECT_IMPLEMENT(yq::tachyon::SaveXGFileGesture)

namespace yq::tachyon {
    SaveXGFileGesture::SaveXGFileGesture(TypedID tgt, const std::string& path) : 
        SaveFileGesture("SaveXGFile", {
            .filters = resource_save_filters<XGDocument>(),
            .path    = path,
            .title   = "Save XG to file"
        }), m_target(tgt)
    {
    }
    
    SaveXGFileGesture::~SaveXGFileGesture()
    {
    }
    
    void SaveXGFileGesture::save(const std::string& s) 
    {
        send(new SaveXGFileCommand({.target=m_target}, s));
    }
}

