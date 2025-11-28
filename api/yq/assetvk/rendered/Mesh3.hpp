////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/aspect/AColor.hpp>
#include <yq/tachyon/aspect/AMaterial.hpp>
#include <yq/tachyon/aspect/AMesh.hpp>
#include <yq/tachyon/data/ColorVertexData.hpp>
#include <yq/tachyon/interface/ITopology.hpp>
#include <yq/tachyon/interface/IVertices.hpp>
#include <yq/tachyon/interface/IVertices3.hpp>
#include <yq/tachyon/pipeline/VBO.hpp>
#include <yq/tachyon/pipeline/UBO.hpp>
#include <yq/tachyon/rendered/Shape3.hpp>

namespace yq::tachyon {
    class Mesh³ : public Shape³, 
        public AColor, 
        public AMesh, 
        public AMaterial, 
        public ITopology,
        public IVertices, 
        public IVertices³ 
    {
        
        YQ_TACHYON_DECLARE(Mesh³, Shape³)
    public:
    
        //   In a contest, the material is taken over the texture
    
        static void init_meta();

        Mesh³(const Param&p={});
        Mesh³(const MeshCPtr&, const Param&p={});
        virtual ~Mesh³();
        
        using IVertices³::vertex;
        using IVertices³::vertices;
        using IVertices::vertices;
    
        virtual uint8_t     vertices(dimension_k) const override { return 3; }
        virtual size_t      vertices(count_k) const override;

        virtual bool        vertices(color_k) const override;
        virtual bool        vertices(tex_k) const override;
        virtual bool        vertices(normal_k) const override;
        virtual bool        vertices(point_k) const override;

        virtual Vector3D    vertex(size_t, point_k) const override;
        virtual RGBA4F      vertex(size_t, color_k) const override;
        virtual UV2F        vertex(size_t, tex_k) const override;
        virtual Vector3F    vertex(size_t, normal_k) const override;

        virtual Topology    topology() const override;

        /*
            Idea #1 is to have rendereds with a "template" flag to disable rendering,
            but allow for instance objects to apply different world matrices 
            to them
        */
        /*
            Idea #2 lean toward the multi-aspect object, reducing the rendered counts.
            Material preempts Texture preempts Color.  Though, color (& bgcolor) would 
            allow for tainting of materials
        */
        /*
            Idea #3 rewrite the Abstract Shape to handle most of this, 
            still keeping the box/tetrahedron/etc
        */

        Execution           setup(const Context&) override;
        Execution           tick(const Context&) override;

    private:
    
        void    rebuild();  // called for all updates

        VB1<VertexT>    m_vboT;
        VB1<VertexS>    m_vboS;
        IB1<uint32_t>   m_ibo;
        UB1<UBS>        m_ubo;
    };
}
