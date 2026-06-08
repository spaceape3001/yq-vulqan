////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/api/TachyonData.hpp>
#include <yq/tachyon/typedef/cursor.hpp>

namespace yq::tachyon {
    class CursorSnap : public TachyonSnap {
        YQ_OBJECT_DECLARE(CursorSnap, TachyonSnap)
    public:
    
        CursorSnap();
        virtual ~CursorSnap();
        static void init_meta();
    };
    
    class CursorData : public TachyonData {
        YQ_OBJECT_DECLARE(CursorData, TachyonData)
    public:
    
        CursorData();
        virtual ~CursorData();
        static void init_meta();
    };
}
