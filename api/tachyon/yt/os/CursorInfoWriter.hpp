////////////////////////////////////////////////////////////////////////////////
//
//  YOUR QUILL
//
////////////////////////////////////////////////////////////////////////////////

#pragma once

#include <yt/os/Cursor.hpp>
#include <yt/os/CursorData.hpp>
#include <yt/api/TachyonInfoWriter.hpp>

namespace yq::tachyon {
    template <typename C>
    class CursorInfo::Writer : public TachyonInfo::Writer<C> {
    public:
        Writer(CursorInfo* cursorInfo) : TachyonInfo::Writer<C>(cursorInfo)
        {
        }
        
        Writer(CursorInfo& cursorInfo) : Writer(&cursorInfo)
        {
        }
    };

}
