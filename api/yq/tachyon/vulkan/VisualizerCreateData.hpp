////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "ViVisualizer.hpp"

#include <yq/tachyon/vulkan/ViDevice.hpp>
#include <yq/tachyon/vulkan/ViSurface.hpp>
#include <yq/tachyon/app/ViewerCreateInfo.hpp>
#include <yq/tachyon/typedef/vi_queue_id.hpp>

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
