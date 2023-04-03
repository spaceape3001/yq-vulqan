////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/Camera.hpp>
#include <basic/meta/ObjectInfoWriter.hpp>

namespace yq {
    namespace tachyon {
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
}
