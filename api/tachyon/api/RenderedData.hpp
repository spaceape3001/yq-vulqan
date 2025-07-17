////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

//#include <yq/config/glm.hpp>
#include <yq/core/Tristate.hpp>
#include <yq/container/BasicBuffer.hpp>
#include <tachyon/pipeline/Buffer.hpp>
#include <tachyon/api/TachyonData.hpp>
#include <tachyon/typedef/buffer.hpp>
#include <tachyon/typedef/push.hpp>
#include <tachyon/typedef/rendered.hpp>
#include <tachyon/typedef/texture.hpp>
#include <tachyon/typedef/vi_buffer.hpp>
#include <tachyon/typedef/vi_texture.hpp>

namespace yq::tachyon {
    class Pipeline;
    
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
        RenderedData();
        ~RenderedData();
    };
}
