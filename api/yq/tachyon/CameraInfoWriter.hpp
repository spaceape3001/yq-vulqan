////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/Camera.hpp>
#include <yq/meta/ObjectInfoWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class CameraInfo::Writer : public ObjectInfo::Writer<C> {
    public:
        Writer(CameraInfo* cameraInfo) : ObjectInfo::Writer<C>(cameraInfo)
        {
        }
        
        Writer(CameraInfo& cameraInfo) : Writer(&cameraInfo)
        {
        }
    };

}
