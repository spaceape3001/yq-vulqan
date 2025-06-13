////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/interface/IVertices3.hpp>
#include <tachyon/api/Tachyon.hpp>
#include <tachyon/data/Vertex3.hpp>
#include <array>
#include <vector>

namespace yq::tachyon {
    
    class AppendVertex³Command;
    class EraseVertexCommand;
    class InsertVertex³Command;
    class SetVertex³Command;
    class SetVertexColorCommand;
    class SetVertexPoint³Command;
    class SetVertexNormal³Command;
    class SetVertexUVCommand;

    template <size_t N=0> class AVertices³;
    
    template <size_t N>
    class AVertices³ : public IVertices³, public virtual Tachyon::Helper {
    public:
 
        static constexpr bool   IsFixed    = (N!=0);
        using vertex_array_t  = std::conditional<IsFixed,std::array<Vertex³,N>,std::vector<Vertex³>>::type;
    
        virtual size_t      vertices(count_k) const
        {
            if constexpr (IsFixed){
                return N;
            } else 
                return m_vertices.size();
        }
        
        virtual size_t      vertices(maximum_k) const
        {
            if constexpr (IsFixed){
                return N;
            } else 
                return SIZE_MAX;
        }
        
        virtual size_t      vertices(minimum_k) const 
        { 
            if constexpr (IsFixed){
                return N;
            } else 
                return 0;
        }

        virtual bool        vertices(appendable_k) const
        {
            return vertices(COUNT) < vertices(MAXIMUM);
        }
        
        virtual bool        vertices(insertable_k) const
        {
            return vertices(COUNT) < vertices(MAXIMUM);
        }
        
        virtual bool        vertices(erasable_k) const
        {
            return vertices(COUNT) > vertices(MINIMUM);
        }
        
        //  future idea
        virtual bool        vertices(swapable_k) const { return false; }

        //  likely want to override these if you're doing things....

        virtual bool        vertices(settable_k) const { return true; }
        virtual bool        vertices(disabled_k) const { return false; }
        virtual bool        vertices(color_k) const { return false; }
        virtual bool        vertices(tex_k) const { return false; }
        virtual bool        vertices(normal_k) const { return false; }

        virtual Vertex³     vertex(size_t) const;
        virtual Vector3D    vertex(size_t, point_k) const;
        virtual RGBA4F      vertex(size_t, color_k) const;
        virtual UV2F        vertex(size_t, tex_k) const;
        virtual Vector3F    vertex(size_t, normal_k) const;

        virtual void        vertex(append_k, const Vertex³&);
        virtual void        vertex(size_t, set_k, const Vertex³&);
        virtual void        vertex(size_t, set_k, const Vector3D&);
        virtual void        vertex(size_t, set_k, color_k, const RGBA4F&);
        virtual void        vertex(size_t, set_k, tex_k, const UV2F&);
        virtual void        vertex(size_t, set_k, normal_k, const Vector3F&);
        virtual void        vertex(size_t, insert_k, const Vertex³&);
        virtual void        vertex(size_t, erase_k);

    protected:
        AVertices³(){}
        ~AVertices³(){}
        vertex_array_t   m_vertices;

        void    on_append_vertex_command(const AppendVertex³Command&);
        void    on_erase_vertex_command(const EraseVertexCommand&);
        void    on_insert_vertex_command(const InsertVertex³Command&);
        void    on_set_vertex_command(const SetVertex³Command&);
        void    on_set_vertex_color_command(const SetVertexColorCommand&);
        void    on_set_vertex_normal_command(const SetVertexNormal³Command&);
        void    on_set_vertex_point_command(const SetVertexPoint³Command&);
        void    on_set_vertex_uv_command(const SetVertexUVCommand&);

        template <typename C>
        static void init_info(TachyonInfo::Writer<C>&);
    };
}
