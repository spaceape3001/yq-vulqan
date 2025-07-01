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
    class CursorInfo::Writer : public TachyonMeta::Writer<C> {
    public:
        Writer(CursorInfo* cursorInfo) : TachyonMeta::Writer<C>(cursorInfo)
        {
        }
        
        Writer(CursorInfo& cursorInfo) : Writer(&cursorInfo)
        {
        }
    };

}
