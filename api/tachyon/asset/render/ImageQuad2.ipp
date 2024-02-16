////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "ImageQuad2.hpp"
#include <glm/glm.hpp>
#include <tachyon/Image.hpp>
#include <tachyon/Shader.hpp>
#include <tachyon/scene/Render3DWriter.hpp>
#include <0/math/shape/AxBox2.hpp>

namespace yq::tachyon {

    void ImageQuad2::initInfo()
    {
        auto w = writer<ImageQuad2>();
        {
            auto p = w.pipeline();
            p.shaders({ "assets/ImageQuad2.vert", "assets/ImageQuad2.frag" });
            p.vertex(&ImageQuad2::m_vertex, DataActivity::FIXED)
                .attribute<glm::vec2>(&VData::position)
                .attribute<glm::vec2>(&VData::uv)
            ;
            p.topology(Topology::TriangleStrip);
            p.front(FrontFace::CounterClockwise);
            p.texture(&ImageQuad2::m_texture, DataActivity::FIXED);
            p.push_full();
        }
    }

    ImageQuad2::ImageQuad2(const AxBox2D&box, std::string_view szImage)
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

        Ref<const Image>    img = Image::load(szImage);
        m_texture           = new Texture(img, ImageViewInfo(), SamplerInfo());
    }
    
    ImageQuad2::~ImageQuad2()
    {
    }


    YQ_INVOKE(
        ImageQuad2::initInfo();
    );
}

YQ_OBJECT_IMPLEMENT(yq::tachyon::ImageQuad2)
