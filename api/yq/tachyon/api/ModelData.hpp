////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/typedef/model.hpp>

namespace yq::tachyon {
    class ModelSnap : public TachyonSnap {
        YQ_OBJECT_DECLARE(ModelSnap, TachyonSnap)
    public:
    
        ModelSnap();
        virtual ~ModelSnap();
        
        static void init_meta();
    };
    
    class ModelData : public TachyonData {
        YQ_OBJECT_DECLARE(ModelData, TachyonData)
    public:
        ModelData();
        virtual ~ModelData();
        static void init_meta();
    };
}
