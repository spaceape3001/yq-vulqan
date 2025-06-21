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

namespace yq::tachyon {
    template <size_t N>
    Vertex³     AVertices³<N>::vertex(size_t n) const
    {
        if(n && (n<=m_vertices.size()))
            return m_vertices[n-1];
        return {};
    }

    template <size_t N>
    Vector3D    AVertices³<N>::vertex(size_t n, point_k) const
    {
        if(n && (n<=m_vertices.size()))
            return m_vertices[n-1].point;
        return {};
    }

    template <size_t N>
    RGBA4F      AVertices³<N>::vertex(size_t n, color_k) const
    {
        if(n && (n<=m_vertices.size()))
            return m_vertices[n-1].color;
        return {};
    }

    template <size_t N>
    UV2F        AVertices³<N>::vertex(size_t n, tex_k) const
    {
        if(n && (n<=m_vertices.size()))
            return m_vertices[n-1].uv;
        return {};
    }

    template <size_t N>
    Vector3F    AVertices³<N>::vertex(size_t n, normal_k) const
    {
        if(n && (n<=m_vertices.size()))
            return m_vertices[n-1].normal;
        return {};
    }

    template <size_t N>
    void        AVertices³<N>::vertex(append_k, const Vertex³&v)
    {
        if constexpr (!IsFixed){
            if(vertices(APPENDABLE)){
                m_vertices.push_back(v);
                mark();
            }
        }
    }

    template <size_t N>
    void        AVertices³<N>::vertex(size_t n, set_k, const Vertex³&v)
    {
        if(vertices(SETTABLE) && n && (n<=m_vertices.size())){
            m_vertices[n-1] = v;
            mark();
        }
    }

    template <size_t N>
    void        AVertices³<N>::vertex(size_t n, set_k, point_k, const Vector3D&v)
    {
        if(vertices(SETTABLE) && n && (n<=m_vertices.size())){
            m_vertices[n-1].point   = v;
            mark();
        }
    }

    template <size_t N>
    void        AVertices³<N>::vertex(size_t n, set_k, color_k, const RGBA4F&v)
    {
        if(vertices(SETTABLE) && n && (n<=m_vertices.size())){
            m_vertices[n-1].color = v;
            mark();
        }
    }

    template <size_t N>
    void        AVertices³<N>::vertex(size_t n, set_k, tex_k, const UV2F& v)
    {
        if(vertices(SETTABLE) && n && (n<=m_vertices.size())){
            m_vertices[n-1].uv = v;
            mark();
        }
    }

    template <size_t N>
    void        AVertices³<N>::vertex(size_t n, set_k, normal_k, const Vector3F& v)
    {
        if(vertices(SETTABLE) && n && (n<=m_vertices.size())){
            m_vertices[n-1].normal = v;
            mark();
        }
    }

    template <size_t N>
    void        AVertices³<N>::vertex(size_t n, insert_k, const Vertex³& v)
    {
        if constexpr (!IsFixed){
            if(vertices(INSERTABLE) && n && (n<=m_vertices.size())){
                m_vertices.insert(m_vertices.begin()+n-1, v);
                mark();
            }
        }
    }

    template <size_t N>
    void        AVertices³<N>::vertex(size_t n, erase_k)
    {
        if constexpr (!IsFixed){
            if(vertices(ERASABLE) && n && (n<=m_vertices.size())){
                m_vertices.erase(m_vertices.begin()+n-1);
                mark();
            }
        }
    }

    template <size_t N>
    void    AVertices³<N>::on_append_vertex_command(const AppendVertex³Command&cmd)
    {
        if(cmd.target() != typed()) 
            return ;
        vertex(APPEND, cmd.data());
    }

    template <size_t N>
    void    AVertices³<N>::on_erase_vertex_command(const EraseVertexCommand&cmd)
    {
        if(cmd.target() != typed()) 
            return ;
        vertex(cmd.vertex(), ERASE);
    }

    template <size_t N>
    void    AVertices³<N>::on_insert_vertex_command(const InsertVertex³Command& cmd)
    {
        if(cmd.target() != typed()) 
            return ;
        vertex(cmd.vertex(), INSERT, cmd.data());
    }

    template <size_t N>
    void        AVertices³<N>::on_set_vertex_command(const SetVertex³Command& cmd)
    {
        if(cmd.target() != typed()) 
            return ;
        vertex(cmd.vertex(), SET, cmd.data());
    }
    
    template <size_t N>
    void        AVertices³<N>::on_set_vertex_color_command(const SetVertexColorCommand& cmd)
    {
        if(cmd.target() != typed()) 
            return ;
        vertex(cmd.vertex(), SET, COLOR, cmd.color());
    }
    
    template <size_t N>
    void        AVertices³<N>::on_set_vertex_normal_command(const SetVertexNormal³Command& cmd)
    {
        if(cmd.target() != typed()) 
            return ;
        vertex(cmd.vertex(), SET, NORMAL, cmd.normal());
    }
    
    template <size_t N>
    void        AVertices³<N>::on_set_vertex_point_command(const SetVertexPoint³Command& cmd)
    {
        if(cmd.target() != typed()) 
            return ;
        vertex(cmd.vertex(), SET, POINT, cmd.point());
    }
    
    template <size_t N>
    void        AVertices³<N>::on_set_vertex_uv_command(const SetVertexUVCommand& cmd)
    {
        if(cmd.target() != typed()) 
            return ;
        vertex(cmd.vertex(), SET, TEX, cmd.uv());
    }
}
