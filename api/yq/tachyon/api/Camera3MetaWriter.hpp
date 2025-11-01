////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Camera3.hpp>
#include <tachyon/api/Camera3Data.hpp>
#include <tachyon/api/CameraMetaWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class Camera³Meta::Writer : public CameraMeta::Writer<C> {
    public:
        Writer(Camera³Meta* cameraInfo) : CameraMeta::Writer<C>(cameraInfo)
        {
        }
        
        Writer(Camera³Meta& cameraInfo) : Writer(&cameraInfo)
        {
        }
    };

}
