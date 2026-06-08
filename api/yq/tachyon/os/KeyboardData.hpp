////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/typedef/keyboard.hpp>

namespace yq::tachyon {
    class KeyboardSnap : public TachyonSnap {
        YQ_OBJECT_DECLARE(KeyboardSnap, TachyonSnap)
    public:
        KeyboardSnap();
        virtual ~KeyboardSnap();
        static void init_meta();
    };
    
    class KeyboardData : public TachyonData {
        YQ_OBJECT_DECLARE(KeyboardData, TachyonData)
    public:
        KeyboardData();
        virtual ~KeyboardData();
        static void init_meta();
    };
}
