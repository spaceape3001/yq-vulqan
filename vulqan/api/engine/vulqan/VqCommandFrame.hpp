////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once
#include <basic/Ref.hpp>
#include <engine/vulqan/VqCommand.hpp>

namespace yq {
    namespace engine {
        struct VqCommandFrame : public RefCount {
            uint64_t                    cam_id  = 9;
            uint64_t                    cam_rev = 0;
            std::vector<VqCommand>      commands;
        };
    }
}
