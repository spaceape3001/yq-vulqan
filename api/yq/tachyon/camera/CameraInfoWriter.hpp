////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/camera/Camera.hpp>
#include <yq/tachyon/core/TachyonInfoWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class CameraInfo::Writer : public TachyonInfo::Writer<C> {
    public:
        Writer(CameraInfo* cameraInfo) : TachyonInfo::Writer<C>(cameraInfo)
        {
        }
        
        Writer(CameraInfo& cameraInfo) : Writer(&cameraInfo)
        {
        }
    };

}
