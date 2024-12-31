////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/Camera³.hpp>
#include <yq/tachyon/api/Camera³Data.hpp>
#include <yq/tachyon/api/CameraInfoWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class CameraInfo³::Writer : public CameraInfo::Writer<C> {
    public:
        Writer(CameraInfo³* cameraInfo) : CameraInfo::Writer<C>(cameraInfo)
        {
        }
        
        Writer(CameraInfo³& cameraInfo) : Writer(&cameraInfo)
        {
        }
    };

}
