////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/scene/Camera.hpp>
#include <yt/scene/CameraData.hpp>
#include <yq/tachyon/api/TachyonInfoWriter.hpp>

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
