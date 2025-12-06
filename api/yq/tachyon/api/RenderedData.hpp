////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

//#include <yq/config/glm.hpp>
#include <yq/core/Tristate.hpp>
#include <yq/container/BasicBuffer.hpp>
#include <yq/container/EnumMap.hpp>
#include <yq/tachyon/pipeline/Buffer.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/enum/RenderMode.hpp>
#include <yq/tachyon/typedef/buffer.hpp>
#include <yq/tachyon/typedef/push.hpp>
#include <yq/tachyon/typedef/rendered.hpp>
#include <yq/tachyon/typedef/texture.hpp>
#include <yq/tachyon/typedef/vi_buffer.hpp>
#include <yq/tachyon/typedef/vi_texture.hpp>

namespace yq::tachyon {
    class Pipeline;
    
    struct RenderedSnap : public TachyonSnap {
        PushBuffer              push;
        Buffered                ibo;  //< Buffered defined in vi_buffer.hpp (as Buffer or ViBuffer)
        std::vector<Buffered>   ubos; //< Buffered defined in vi_buffer.hpp (as Buffer or ViBuffer)
        std::vector<Buffered>   vbos; //< Buffered defined in vi_buffer.hpp (as Buffer or ViBuffer)
        std::vector<Buffered>   sbos; //< Buffered defined in vi_buffer.hpp (as Buffer or ViBuffer)
        std::vector<Textured>   texs; //< Textured defined in vi_texture.hpp (as Texture or ViTexture)
        
        const Pipeline*         pipeline(RenderMode rm=RenderMode::Simple) const;
        
        const Pipeline*         pipeline_simple = nullptr;
        const Pipeline*         pipeline_light  = nullptr;
        const Pipeline*         pipeline_ray    = nullptr;
        //uint32_t                draw_vertex     = 0;
        //uint32_t                draw_instance   = 0;
        Tristate                wireframe       = Tristate::INHERIT;
        Tristate                culled          = Tristate::INHERIT;
        bool                    good            = false;
        
        RenderedSnap();
        ~RenderedSnap();
    };
    
    struct RenderedData : public TachyonData {
        RenderedData();
        ~RenderedData();
    };
}
