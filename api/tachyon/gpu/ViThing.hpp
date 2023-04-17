////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/gpu/ViBO.hpp>
#include <tachyon/preamble.hpp>

namespace yq::tachyon {
    struct ViThing {
        std::vector<ViBO>   vbos;
        std::vector<ViBO>   ibos;
        
        ViThing(Visualizer& viz, const ViPipeline&, const Rendered* object);
        void    update(Visualizer& viz, const ViPipeline&, const Rendered* object);
    };

}
