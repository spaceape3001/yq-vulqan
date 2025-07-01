////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "AVertices3.hpp"
#include <tachyon/command/vertex/AppendVertex3Command.hpp>
#include <tachyon/command/vertex/EraseVertexCommand.hpp>
#include <tachyon/command/vertex/InsertVertex3Command.hpp>
#include <tachyon/command/vertex/SetVertex3Command.hpp>
#include <tachyon/command/vertex/SetVertexColorCommand.hpp>
#include <tachyon/command/vertex/SetVertexNormal3Command.hpp>
#include <tachyon/command/vertex/SetVertexPoint3Command.hpp>
#include <tachyon/command/vertex/SetVertexUVCommand.hpp>
#include <tachyon/api/TachyonMetaWriter.hpp>
#include <tachyon/tags.hpp>

namespace yq::tachyon {
    template <size_t N>
        template <typename C>
    void AVertices³<N>::init_info(TachyonMeta::Writer<C>& w)
    {
        w.template interface<AVertices³<N>>();
        w.slot(UNSAFE, &AVertices³<N>::on_append_vertex_command);
        w.slot(UNSAFE, &AVertices³<N>::on_erase_vertex_command);
        w.slot(UNSAFE, &AVertices³<N>::on_insert_vertex_command);
        w.slot(UNSAFE, &AVertices³<N>::on_set_vertex_command);
        w.slot(UNSAFE, &AVertices³<N>::on_set_vertex_color_command);
        w.slot(UNSAFE, &AVertices³<N>::on_set_vertex_normal_command);
        w.slot(UNSAFE, &AVertices³<N>::on_set_vertex_point_command);
        w.slot(UNSAFE, &AVertices³<N>::on_set_vertex_uv_command);
    }
}
