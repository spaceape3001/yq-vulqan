////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yq/tachyon/os/Cursor.hpp>
#include <yq/tachyon/os/CursorData.hpp>
#include <yq/tachyon/api/TachyonMetaWriter.hpp>

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
