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
        std::vector<ViBO>               vbos;
        std::vector<ViBO>               ibos;
        std::vector<ViBO>               ubos;
        
        std::vector<VkDescriptorSet>    descriptors;        // to MAX_FRAMES_IN_FLIGHT * ibos * ubos needed...
        
        ViThing(Visualizer& viz, const ViPipeline&, const Rendered* object);
        void    update(Visualizer& viz, const ViPipeline&, const Rendered* object);
    };

}
