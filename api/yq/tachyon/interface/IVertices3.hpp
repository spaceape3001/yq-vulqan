////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/keywords.hpp>
#include <yq/typedef/rgba.hpp>
#include <yq/typedef/uv.hpp>
#include <yq/typedef/vector3.hpp>
#include <yq/tachyon/api/Interface.hpp>

namespace yq::tachyon {
    class PVertices³;
    struct Vertex³;
    
    /*! Vertices
    
        Numbering will be 1...N (with zero reserved for invalid)
    */
    class IVertices³ {
    public:
        YQ_INTERFACE_DECLARE(IVertices³, PVertices³)

        virtual size_t      vertices(count_k) const = 0;
        virtual size_t      vertices(maximum_k) const { return SIZE_MAX; }
        virtual size_t      vertices(minimum_k) const { return 0; }
        virtual bool        vertices(appendable_k) const { return false; }
        virtual bool        vertices(disabled_k) const { return false; }
        virtual bool        vertices(insertable_k) const { return false; }
        virtual bool        vertices(settable_k) const { return false; }
        virtual bool        vertices(erasable_k) const { return false; }
        virtual bool        vertices(swapable_k) const { return false; }
        virtual bool        vertices(color_k) const { return false; }
        virtual bool        vertices(tex_k) const { return false; }
        virtual bool        vertices(normal_k) const { return false; }
        virtual bool        vertices(point_k) const { return true; }
        virtual bool        vertices(settable_k, color_k) const { return vertices(SETTABLE) && vertices(COLOR); }
        virtual bool        vertices(settable_k, tex_k) const { return vertices(SETTABLE) && vertices(TEX); }
        virtual bool        vertices(settable_k, normal_k) const { return vertices(SETTABLE) && vertices(NORMAL); }
        virtual bool        vertices(settable_k, point_k) const { return vertices(SETTABLE) && vertices(POINT); }

        virtual Vertex³     vertex(size_t) const;
        virtual Vector3D    vertex(size_t, point_k) const = 0;
        virtual RGBA4F      vertex(size_t, color_k) const;
        virtual UV2F        vertex(size_t, tex_k) const;
        virtual Vector3F    vertex(size_t, normal_k) const;

        virtual void        vertex(append_k, const Vertex³&) {}
        virtual void        vertex(size_t, set_k, const Vertex³&);
        virtual void        vertex(size_t, set_k, point_k, const Vector3D&) {}
        virtual void        vertex(size_t, set_k, color_k, const RGBA4F&) {}
        virtual void        vertex(size_t, set_k, tex_k, const UV2F&) {}
        virtual void        vertex(size_t, set_k, normal_k, const Vector3F&) {}
        virtual void        vertex(size_t, insert_k, const Vertex³&) {}
        virtual void        vertex(size_t, erase_k) {}
        
        static void init_meta();
    };
}

