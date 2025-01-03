////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/3D/Camera3.hpp>
#include <yt/3D/Camera3Data.hpp>
#include <yt/scene/CameraInfoWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class Camera³Info::Writer : public CameraInfo::Writer<C> {
    public:
        Writer(Camera³Info* cameraInfo) : CameraInfo::Writer<C>(cameraInfo)
        {
        }
        
        Writer(Camera³Info& cameraInfo) : Writer(&cameraInfo)
        {
        }
    };

}
