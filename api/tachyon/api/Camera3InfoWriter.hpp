////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Camera3.hpp>
#include <tachyon/api/Camera3Data.hpp>
#include <tachyon/api/CameraInfoWriter.hpp>

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
