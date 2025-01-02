////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/3D/Camera3.hpp>
#include <yq/tachyon/3D/Camera3Data.hpp>
#include <yq/tachyon/scene/CameraInfoWriter.hpp>

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
