////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Camera3.hpp>
#include <yq/tachyon/api/Camera3Data.hpp>
#include <yq/tachyon/api/CameraInfoWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class CameraInfo3::Writer : public CameraInfo::Writer<C> {
    public:
        Writer(CameraInfo3* cameraInfo) : CameraInfo::Writer<C>(cameraInfo)
        {
        }
        
        Writer(CameraInfo3& cameraInfo) : Writer(&cameraInfo)
        {
        }
    };

}
