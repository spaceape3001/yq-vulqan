////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/config/glm.hpp>
#include <yq/container/BasicBuffer.hpp>
#include <yq/tachyon/api/Buffer.hpp>
#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/typedef/rendered.hpp>
#include <yq/tachyon/typedef/push.hpp>
#include <yq/tachyon/typedef/texture.hpp>
#include <yq/tachyon/typedef/vi_buffer.hpp>
#include <yq/tachyon/typedef/vi_texture.hpp>

namespace yq::tachyon {
    struct RenderedSnap : public TachyonSnap {
        using buffer_t   = std::variant<std::monostate, BufferCPtr, ViBufferCPtr>;
        using texture_t  = std::variant<std::monostate, TextureCPtr, ViTextureCPtr>;
    
        PushBuffer              push;
        
        //! Us to the world so xyz = world * uvw
        glm::dmat4              world{  1., 0., 0., 0.,
                                        0., 1., 0., 0., 
                                        0., 0., 1., 0.,
                                        0., 0., 0., 1. }; 
        std::vector<buffer_t>   vbos;
        std::vector<buffer_t>   ibos;
        std::vector<buffer_t>   ubos;
        std::vector<buffer_t>   sbos;
        std::vector<texture_t>  texs;
        const Pipeline*         pipeline        = nullptr;
        uint32_t                draw_vertex     = 0;
        uint32_t                draw_instance   = 0;
        Tristate                wireframe       = Tristate::INHERIT;
        bool                    culled          = false;       
        
        RenderedSnap();
        RenderedSnap(const RenderedSnap&);
        ~RenderedSnap();
    };
    
    struct RenderedData : public TachyonData {
    };
}
