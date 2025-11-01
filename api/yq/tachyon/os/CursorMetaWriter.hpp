////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <tachyon/os/Cursor.hpp>
#include <tachyon/os/CursorData.hpp>
#include <tachyon/api/TachyonMetaWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class CursorMeta::Writer : public TachyonMeta::Writer<C> {
    public:
        Writer(CursorMeta* cursorInfo) : TachyonMeta::Writer<C>(cursorInfo)
        {
        }
        
        Writer(CursorMeta& cursorInfo) : Writer(&cursorInfo)
        {
        }
    };

}
