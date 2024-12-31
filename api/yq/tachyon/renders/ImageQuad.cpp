////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ImageQuad.hpp"

#include <yq/shape/AxBox2.hpp>

#include <yq/tachyon/api/Shader.hpp>
#include <yq/tachyon/api/Rendered3InfoWriter.hpp>

#include <yq/shape/AxBox2.hxx>

namespace yq::tachyon {

    void ImageQuad3::init_info()
    {
        auto w = writer<ImageQuad3>();
        {
            auto& p = w.pipeline();
            p.shaders({ "assets/ImageQuad2.vert", "assets/ImageQuad2.frag" });
            p.vertex(&ImageQuad3::m_vertex, DataActivity::FIXED)
                .attribute<glm::vec2>(&VData::position)
                .attribute<glm::vec2>(&VData::uv)
            ;
            p.topology(Topology::TriangleStrip);
            p.front(FrontFace::CounterClockwise);
            p.texture(&ImageQuad3::m_texture, DataActivity::FIXED);
            p.push_full();
        }
    }

    ImageQuad3::ImageQuad3(const AxBox2D&box, std::string_view szImage, const Param& p) : Rendered3(p)
    {
        glm::dvec2  ll  = box.ll();
        glm::dvec2  lh  = box.lh();
        glm::dvec2  hl  = box.hl();
        glm::dvec2  hh  = box.hh();
        
        m_vertex = { 
            { ll, { 0., 0. }},
            { lh, { 0., 1. }},
            { hl, { 1., 0. }}, 
            { hh, { 1., 1. }}
        };

        m_texture           = Texture::load(szImage);
    }
    
    ImageQuad3::~ImageQuad3()
    {
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::ImageQuad3)

