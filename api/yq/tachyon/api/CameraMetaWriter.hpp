////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Camera.hpp>
#include <yq/tachyon/api/CameraData.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class CameraMeta::Writer : public TachyonMeta::Writer<C> {
    public:
        Writer(CameraMeta* cameraInfo) : TachyonMeta::Writer<C>(cameraInfo)
        {
        }
        
        Writer(CameraMeta& cameraInfo) : Writer(&cameraInfo)
        {
        }
    };

}
