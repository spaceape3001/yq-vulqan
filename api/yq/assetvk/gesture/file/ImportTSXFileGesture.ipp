////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ImportTSXFileGesture.hpp"
#include <yq/tachyon/api/GestureMetaWriter.hpp>
#include <yq/tachyon/command/file/ImportTSXFileCommand.hpp>
#include <yq/tachyon/io/Save.hpp>
#include <yq/tachyon/io/ResourceFilters.hxx>

YQ_OBJECT_IMPLEMENT(yq::tachyon::ImportTSXFileGesture)

namespace yq::tachyon {
    ImportTSXFileGesture::ImportTSXFileGesture(TypedID tgt, const std::string& path) : 
        OpenFileGesture("ImportTSXFile", {
            .filters = resource_load_filters<Save>(),
            .path    = path,
            .title   = "Pick TSX to Import"
        }), m_target(tgt)
    {
    }
    
    ImportTSXFileGesture::~ImportTSXFileGesture()
    {
    }
    
    void ImportTSXFileGesture::open(const std::string& s) 
    {
        send(new ImportTSXFileCommand({.target=m_target}, s));
    }
}

