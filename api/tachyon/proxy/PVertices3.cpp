////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "PVertices3.hpp"

#include <tachyon/interface/IVertices3.hpp>
#include <tachyon/data/Vertex3.hpp>
#include <tachyon/command/vertex/AppendVertex3Command.hpp>
#include <tachyon/command/vertex/EraseVertexCommand.hpp>
#include <tachyon/command/vertex/InsertVertex3Command.hpp>
#include <tachyon/command/vertex/SetVertex3Command.hpp>
#include <tachyon/command/vertex/SetVertexColorCommand.hpp>
#include <tachyon/command/vertex/SetVertexNormal3Command.hpp>
#include <tachyon/command/vertex/SetVertexPoint3Command.hpp>
#include <tachyon/command/vertex/SetVertexUVCommand.hpp>

namespace yq::tachyon {
    PVertices³::PVertices³(const IVertices³&i) :
        m_count(i.vertices(COUNT)),
        m_maxCount(i.vertices(MAXIMUM)),
        m_minCount(i.vertices(MINIMUM))
    {
        if(i.vertices(APPENDABLE))
            m_pflags |= P::Appendable;
        if(i.vertices(DISABLED))
            m_flags  |= F::Disabled;
        if(i.vertices(INSERTABLE))
            m_pflags |= P::Insertable;
        if(i.vertices(SETTABLE))
            m_pflags |= P::Settable;
        if(i.vertices(ERASABLE))
            m_pflags |= P::Erasable;
        if(i.vertices(COLOR))
            m_pflags |= P::Color;
        if(i.vertices(TEX))
            m_pflags |= P::Tex;
        if(i.vertices(NORMAL))
            m_pflags |= P::Normal;
            
        if(!m_count)
            return ;
            
        m_vertices.resize(m_count);
        for(size_t n=0; n<m_count; ++n)
            m_vertices[n] = i.vertex(n+1, POINT);
        
        if(m_pflags(P::Color)){
            m_colors.resize(m_count);
            for(size_t n=0; n<m_count; ++n)
                m_colors[n] = i.vertex(n+1, COLOR);
        }
        
        if(m_pflags(P::Tex)){
            m_texs.resize(m_count);
            for(size_t n=0; n<m_count; ++n)
                m_texs[n] = i.vertex(n+1, TEX);
        }
        
        if(m_pflags(P::Normal)){
            m_normals.resize(m_count);
            for(size_t n=0; n<m_count; ++n)
                m_normals[n] = i.vertex(n+1, NORMAL);
        }
        
        //  And if we add in more properties to vertices... add the copy here...
    }
    
    PVertices³::~PVertices³() = default;
    
    ////////////////////////////////

    size_t      PVertices³::vertices(count_k) const
    {
        return m_count;
    }
    
    size_t      PVertices³::vertices(maximum_k) const
    {
        return m_maxCount;
    }
    
    size_t      PVertices³::vertices(minimum_k) const
    {
        return m_minCount;
    }
    
    bool        PVertices³::vertices(appendable_k) const
    {
        return m_pflags(P::Appendable);
    }
    
    bool        PVertices³::vertices(disabled_k) const
    {
        return m_flags(F::Disabled);
    }
    
    bool        PVertices³::vertices(insertable_k) const
    {
        return m_pflags(P::Insertable);
    }
    
    bool        PVertices³::vertices(settable_k) const
    {
        return m_pflags(P::Settable);
    }
    
    bool        PVertices³::vertices(erasable_k) const
    {
        return m_pflags(P::Erasable);
    }
    
    bool        PVertices³::vertices(color_k) const
    {
        return m_pflags(P::Color);
    }
    
    bool        PVertices³::vertices(tex_k) const
    {
        return m_pflags(P::Tex);
    }
    
    bool        PVertices³::vertices(normal_k) const
    {
        return m_pflags(P::Normal);
    }

    Vertex³      PVertices³::vertex(size_t n) const
    {
        Vertex³  ret;
        if(n){
            if(n <= m_vertices.size())
                ret.point   = m_vertices[n-1];
            if(n <= m_colors.size())
                ret.color   = m_colors[n-1];
            if(n <= m_texs.size())
                ret.uv      = m_texs[n-1];
            if(n <= m_normals.size())
                ret.normal  = m_normals[n-1];
        }
        return ret;
    }
    
    Vector3D    PVertices³::vertex(size_t n, point_k) const
    {
        if(n && (n<=m_vertices.size()))
            return m_vertices[n-1];
        return ZERO;
    }
    
    RGBA4F      PVertices³::vertex(size_t n, color_k) const
    {
        if(n && (n<=m_colors.size()))
            return m_colors[n-1];
        return {};
    }
    
    UV2F        PVertices³::vertex(size_t n, tex_k) const
    {
        if(n && (n<=m_texs.size()))
            return m_texs[n-1];
        return {};
    }
    
    Vector3F    PVertices³::vertex(size_t n, normal_k) const
    {
        if(n && (n<=m_normals.size()))
            return m_normals[n-1];
        return ZERO;
    }

    void        PVertices³::vertex(append_k, const Vertex³&v) 
    { 
        if(m_pflags(P::Appendable) && !m_flags(F::Disabled)){
            mail(new AppendVertex³Command({.target=object()}, v));
        }
    }
    
    void        PVertices³::vertex(size_t n, set_k, const Vertex³&v)
    {
        if(m_pflags(P::Settable) && !m_flags(F::Disabled)){
            mail(new SetVertex³Command({.target=object()}, n, v));
        }
    }
    
    void        PVertices³::vertex(size_t n, set_k, point_k, const Vector3D& v) 
    { 
        if(m_pflags(P::Settable) && !m_flags(F::Disabled)){
            mail(new SetVertexPoint³Command({.target=object()}, n, v));
        }
    }
    
    void        PVertices³::vertex(size_t n, set_k, color_k, const RGBA4F&v) 
    { 
        if(m_pflags(P::Settable) && m_pflags(P::Color) && !m_flags(F::Disabled)){
            mail(new SetVertexColorCommand({.target=object()}, n, v));
        }
    }
    
    void        PVertices³::vertex(size_t n, set_k, tex_k, const UV2F& v) 
    { 
        if(m_pflags(P::Settable) && m_pflags(P::Tex) && !m_flags(F::Disabled)){
            mail(new SetVertexUVCommand({.target=object()}, n, v));
        }
    }
    
    void        PVertices³::vertex(size_t n, set_k, normal_k, const Vector3F& v) 
    { 
        if(m_pflags(P::Settable) && m_pflags(P::Normal) && !m_flags(F::Disabled)){
            mail(new SetVertexNormal³Command({.target=object()}, n, v));
        }
    }

    void        PVertices³::vertex(size_t n, erase_k) 
    { 
        if(m_pflags(P::Erasable) && !m_flags(F::Disabled)){
            mail(new EraseVertexCommand({.target=object()}, n));
        }
    }

    void        PVertices³::vertex(size_t n, insert_k, const Vertex³&v) 
    { 
        if(m_pflags(P::Insertable) && !m_flags(F::Disabled)){
            mail(new InsertVertex³Command({.target=object()}, n, v));
        }
    }

}
