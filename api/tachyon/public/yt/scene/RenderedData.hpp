////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

//#include <yq/config/glm.hpp>
#include <yq/core/Tristate.hpp>
#include <yq/container/BasicBuffer.hpp>
#include <yt/gfx/Buffer.hpp>
#include <yt/api/TachyonData.hpp>
#include <yt/typedef/buffer.hpp>
#include <yt/typedef/push.hpp>
#include <yt/typedef/rendered.hpp>
#include <yt/typedef/texture.hpp>
#include <yv/typedef/vi_buffer.hpp>
#include <yv/typedef/vi_texture.hpp>

namespace yq::tachyon {
    struct RenderedSnap : public TachyonSnap {
        PushBuffer              push;
        std::vector<Buffered>   ibos; //< Buffered defined in vi_buffer.hpp (as Buffer or ViBuffer)
        std::vector<Buffered>   ubos; //< Buffered defined in vi_buffer.hpp (as Buffer or ViBuffer)
        std::vector<Buffered>   vbos; //< Buffered defined in vi_buffer.hpp (as Buffer or ViBuffer)
        std::vector<Buffered>   sbos; //< Buffered defined in vi_buffer.hpp (as Buffer or ViBuffer)
        std::vector<Textured>   texs; //< Textured defined in vi_texture.hpp (as Texture or ViTexture)
        const Pipeline*         pipeline        = nullptr;
        //uint32_t                draw_vertex     = 0;
        //uint32_t                draw_instance   = 0;
        Tristate                wireframe       = Tristate::INHERIT;
        Tristate                culled          = Tristate::INHERIT;
        
        RenderedSnap();
        ~RenderedSnap();
    };
    
    struct RenderedData : public TachyonData {
    };
}
