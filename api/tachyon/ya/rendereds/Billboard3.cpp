////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include <ya/rendereds/Billboard3.hpp>

#include <yq/shape/AxBox2.hpp>

#include <tachyon/gfx/Shader.hpp>
#include <yt/3D/Rendered3InfoWriter.hpp>

#include <yq/shape/AxBox2.hxx>

namespace yq::tachyon {

    void Billboard³::init_info()
    {
        auto w = writer<Billboard³>();
        {
            auto& p = w.pipeline();
            p.shaders({ "assets/Billboard3.vert", "assets/Billboard3.frag" });
            p.vertex(&Billboard³::m_vertex, DataActivity::FIXED)
                .attribute<glm::vec2>(&VData::position)
                .attribute<glm::vec2>(&VData::uv)
            ;
            p.topology(Topology::TriangleStrip);
            p.front(FrontFace::CounterClockwise);
            p.texture(&Billboard³::m_texture, DataActivity::FIXED);
            p.push_mvp();
        }
    }

    Billboard³::Billboard³(const AxBox2D&box, std::string_view szImage, const Param& p) : Rendered³(p)
    {
        glm::dvec2  ll  = box.ll();
        glm::dvec2  lh  = box.lh();
        glm::dvec2  hl  = box.hl();
        glm::dvec2  hh  = box.hh();
        
        m_vertex = { 
            { ll, { 0., 0. }},
            { hl, { 1., 0. }}, 
            { lh, { 0., 1. }},
            { hh, { 1., 1. }}
        };

        m_texture           = Texture::load(szImage);
    }
    
    void        Billboard³::snap(Rendered³Snap& sn) const
    {
        Rendered³::snap(sn);
        sn.vm_override  =  false;
        sn.vm_tensor.xx = 1.;
        sn.vm_tensor.xy = 0.;
        sn.vm_tensor.xz = 0.;
        sn.vm_tensor.yx = 0.;
        sn.vm_tensor.yy = 1.;
        sn.vm_tensor.yz = 0.;
        sn.vm_tensor.zx = 0.;
        sn.vm_tensor.zy = 0.;
        sn.vm_tensor.zz = 1.;
        
    }

    Billboard³::~Billboard³()
    {
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::Billboard³)

