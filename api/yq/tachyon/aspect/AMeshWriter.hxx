////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/tags.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>
#include <yq/tachyon/aspect/AMesh.hpp>
#include <yq/tachyon/asset/Mesh.hpp>
#include <yq/tachyon/command/shape/SetMeshCommand.hpp>
#include <yq/tachyon/command/shape/SetMeshUrlCommand.hpp>

namespace yq::tachyon {
    template <typename C>
    void AMesh::init_meta(TachyonMeta::Writer<C>&w)
    {
        w.template interface<IMesh>();
        w.resource( "mesh", &AMesh::m_mesh).tag(kTag_Save);

        w.slot(UNSAFE, &AMesh::on_set_mesh);
        w.slot(UNSAFE, &AMesh::on_set_mesh_url);
    }
}
