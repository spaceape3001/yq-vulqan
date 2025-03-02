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

namespace yq::tachyon {
    struct ViVisualizer::CreateData {
        ViDevicePtr             device;
        ViSurfacePtr            surface;
        ViewerCreateInfo        viewer;
        Size2I                  pixels;
    };
}
