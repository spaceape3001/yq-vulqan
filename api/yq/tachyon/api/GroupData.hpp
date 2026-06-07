////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/api/TypedID.hpp>
#include <yq/tachyon/typedef/scene.hpp>
#include <yq/color/RGBA.hpp>

namespace yq::tachyon {
    class GroupSnap : public TachyonSnap {
        YQ_OBJECT_DECLARE(GroupSnap, TachyonSnap)
    public:
        int         order = 0;
        
        GroupSnap();
        virtual ~GroupSnap();
        static void init_meta();
    };
    
    class GroupData : public TachyonData {
        YQ_OBJECT_DECLARE(GroupData, TachyonData)
    public:
    
        GroupData();
        virtual ~GroupData();
        static void init_meta();
    };
}
