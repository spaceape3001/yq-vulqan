////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PickMeshFileGesture.hpp"
#include <yq/tachyon/api/GestureMetaWriter.hpp>
#include <yq/tachyon/asset/Mesh.hpp>
#include <yq/tachyon/command/mesh/SetMeshSpecCommand.hpp>
#include <yq/tachyon/io/ResourceFilters.hxx>

YQ_OBJECT_IMPLEMENT(yq::tachyon::PickMeshFileGesture)

namespace yq::tachyon {
    PickMeshFileGesture::PickMeshFileGesture(TypedID tgt, const std::string& path) : 
        OpenFileGesture("PickMeshFile", {
            .filters = resource_load_filters<Mesh>(),
            .path    = path,
            .title   = "Pick Mesh File"
        }), m_target(tgt)
    {
    }
    
    PickMeshFileGesture::~PickMeshFileGesture()
    {
    }
    
    void PickMeshFileGesture::open(const std::string& s) 
    {
        send(new SetMeshSpecCommand({.target=m_target}, s));
    }
}

