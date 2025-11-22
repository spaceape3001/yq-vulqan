////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#include "ImageQuad3.hpp"

#include <yq/shape/AxBox2.hpp>

#include <yq/tachyon/asset/Shader.hpp>
#include <yq/tachyon/api/Rendered3MetaWriter.hpp>

#include <yq/shape/AxBox2.hxx>

namespace yq::tachyon {

    void ImageQuad³::init_meta()
    {
        auto w = writer<ImageQuad³>();
        {
            auto& p = w.pipeline();
            p.shaders({ "resources/ImageQuad3.vert", "resources/ImageQuad3.frag" });
            p.vertex(&ImageQuad³::m_vertex, DataActivity::FIXED)
                .attribute<glm::vec2>(&VData::position)
                .attribute<glm::vec2>(&VData::uv)
            ;
            p.topology(Topology::TriangleStrip);
            p.front(FrontFace::CounterClockwise);
            p.texture(&ImageQuad³::m_texture, DataActivity::FIXED);
            p.push_full();
        }
    }

    ImageQuad³::ImageQuad³(const AxBox2D&box, std::string_view szImage, const Param& p) : Rendered³(p)
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
    
    ImageQuad³::~ImageQuad³()
    {
    }
}

YQ_TACHYON_IMPLEMENT(yq::tachyon::ImageQuad³)

