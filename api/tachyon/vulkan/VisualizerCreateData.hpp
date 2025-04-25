////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "ViVisualizer.hpp"

#include <tachyon/vulkan/ViDevice.hpp>
#include <tachyon/vulkan/ViSurface.hpp>
#include <tachyon/app/ViewerCreateInfo.hpp>
#include <tachyon/typedef/vi_queue_id.hpp>

namespace yq::tachyon {
    struct ViVisualizer::CreateData {
        const ViewerCreateInfo& viewer;
        ViDevicePtr             device;
        ViSurfacePtr            surface;
        Size2I                  pixels;
        ViQueueID               present;    //!< States which queue family to use for present support (default is graphic)
        uint32_t                number  = 0;
    };
}
