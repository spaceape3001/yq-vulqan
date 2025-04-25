////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Camera.hpp>
#include <tachyon/api/CameraData.hpp>
#include <tachyon/api/TachyonInfoWriter.hpp>

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
