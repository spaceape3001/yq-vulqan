////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include "ViVisualizer.hpp"

#include <yv/ViDevice.hpp>
#include <yv/ViSurface.hpp>
#include <yt/app/ViewerCreateInfo.hpp>
#include <yv/typedef/vi_queue_id.hpp>

namespace yq::tachyon {
    struct ViVisualizer::CreateData {
        const ViewerCreateInfo& viewer;
        ViDevicePtr             device;
        ViSurfacePtr            surface;
        Size2I                  pixels;
        ViQueueFamilyID         present;    //!< States which queue family to use for present support (default is graphic)
        uint32_t                number  = 0;
    };
}
