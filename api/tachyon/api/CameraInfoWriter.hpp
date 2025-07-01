////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/api/Camera.hpp>
#include <tachyon/api/CameraData.hpp>
#include <tachyon/api/TachyonMetaWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class CameraInfo::Writer : public TachyonMeta::Writer<C> {
    public:
        Writer(CameraInfo* cameraInfo) : TachyonMeta::Writer<C>(cameraInfo)
        {
        }
        
        Writer(CameraInfo& cameraInfo) : Writer(&cameraInfo)
        {
        }
    };

}
