////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/typedef/camera.hpp>

namespace yq::tachyon {
    class CameraSnap : public TachyonSnap {
        YQ_OBJECT_DECLARE(CameraSnap, TachyonSnap)
    public:
        CameraSnap();
        virtual ~CameraSnap();
        static void init_meta();
    };
    
    class CameraData : public TachyonData {
        YQ_OBJECT_DECLARE(CameraData, TachyonData)
    public:
        CameraData();
        virtual ~CameraData();
        static void init_meta();
    };
}
